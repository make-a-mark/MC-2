/*
 * Voice classifier for Arduino Nano 33 BLE Sense by Alan Wang
 */

#include <math.h>
#include <PDM.h>
#include <EloquentTinyML.h>      // https://github.com/eloquentarduino/EloquentTinyML
#include "model.h"       // TF Lite model file

#include <Arduino_APDS9960.h>
#include <Arduino_LSM9DS1.h>

#define PDM_SOUND_GAIN     255   // sound gain of PDM mic
#define PDM_BUFFER_SIZE    256   // buffer size of PDM mic

#define SAMPLE_THRESHOLD   900   // RMS threshold to trigger sampling
#define FEATURE_SIZE       32    // sampling size of one voice instance
#define SAMPLE_DELAY       20    // delay time (ms) between sampling

#define NUMBER_OF_LABELS   3     // number of voice labels
const String words[NUMBER_OF_LABELS] = {"Spotify", "Launch", "Play"};  // words for each label


#define PREDIC_THRESHOLD   0.6   // prediction probability threshold for labels
#define UNCONFIDENCE_THRESH 0.4 // if any prediction is in the range [0.4-0.6], then give an unconfident prediction
#define RAW_OUTPUT         true  // output prediction probability of each label
#define NUMBER_OF_INPUTS   FEATURE_SIZE
#define NUMBER_OF_OUTPUTS  NUMBER_OF_LABELS
#define TENSOR_ARENA_SIZE  4 * 1024


Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> tf_model;
float feature_data[FEATURE_SIZE];
volatile float rms;
bool voice_detected;

float prev_z = 0;
int going_up = 0;
int going_down = 0;
int base = 1;

float x, y, z;

// callback function for PDM mic
void onPDMdata() {

  rms = -1;
  short sample_buffer[PDM_BUFFER_SIZE];
  int bytes_available = PDM.available();
  PDM.read(sample_buffer, bytes_available);

  // calculate RMS (root mean square) from sample_buffer
  unsigned int sum = 0;
  for (unsigned short i = 0; i < (bytes_available / 2); i++) sum += pow(sample_buffer[i], 2);
  rms = sqrt(float(sum) / (float(bytes_available) / 2.0));
}

void setup() {

  Serial.begin(115200);
  while (!Serial);

  PDM.onReceive(onPDMdata);
  PDM.setBufferSize(PDM_BUFFER_SIZE);
  PDM.setGain(PDM_SOUND_GAIN);

  if (!PDM.begin(1, 16000)) {  // start PDM mic and sampling at 16 KHz
    Serial.println("Failed to start PDM!");
    while (1);
  }

  pinMode(LED_BUILTIN, OUTPUT);

  // wait 1 second to avoid initial PDM reading
  delay(900);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);

  // start TF Lite model
  tf_model.begin((unsigned char*) model_data);
  
    if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
    }

    if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
    }

  Serial.println("=== Classifier start ===\n");
}

void loop() {

  // waiting until sampling triggered
  if(rms < SAMPLE_THRESHOLD) 
  {

    digitalWrite(LED_BUILTIN, HIGH);
    for (int i = 0; i < FEATURE_SIZE; i++) {  // sampling
      while (rms < 0);
      feature_data[i] = rms;
      delay(SAMPLE_DELAY);
    }
    digitalWrite(LED_BUILTIN, LOW);

    // predict voice and put results (probability) for each label in the array
    float prediction[NUMBER_OF_LABELS];
    tf_model.predict(feature_data, prediction);

    // print out prediction results;
    // in theory, you need to find the highest probability in the array,
    // but only one of them would be high enough over 0.5~0.6
    Serial.println("Predicting the word:");
    if (RAW_OUTPUT) {
      for (int i = 0; i < NUMBER_OF_LABELS; i++) {
        Serial.print("Label ");
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(prediction[i]);
      }
    }
    voice_detected = false;
    for (int i = 0; i < NUMBER_OF_LABELS; i++) {
      if (prediction[i] >= PREDIC_THRESHOLD) {
        Serial.print("Word detected: ");
        Serial.println(words[i]);
        Serial.println("");
        voice_detected = true;
      }
      else if (prediction[i] >= UNCONFIDENCE_THRESH) {
        Serial.print("Word detected: ");
        Serial.print(words[i]);
        Serial.println("U");
        Serial.println("");
        voice_detected = true;
      }
    }
    if (!voice_detected && !RAW_OUTPUT) Serial.println("Word not recognized\n");

    // wait for 1 second after one sampling/prediction
    delay(900);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (APDS.gestureAvailable()) 
    {
      // a gesture was detected, read and print to serial monitor
      int gesture = APDS.readGesture();
  
      switch (gesture) 
      {
        case GESTURE_UP:
          Serial.println("playpause");
          break;
  
        case GESTURE_DOWN:
          Serial.println("playpause");
          break;
  
        case GESTURE_LEFT:
          Serial.println("PrevTrack");
          break;
  
        case GESTURE_RIGHT:
          Serial.println("NextTrack");
          break;
  
        default:
          // ignore
          break;
      }
    }
    if (IMU.gyroscopeAvailable()) 
    {
      IMU.readGyroscope(x, y, z);
      if (debug_flag)
      {
        Serial.print(z);
        Serial.print("\t");
        Serial.print(prev_z);
        Serial.print("\t");
        Serial.print(going_down);
        Serial.print("\t");
        Serial.print(going_up);
        Serial.print("\t");
        Serial.print(z - prev_z);
        Serial.print("\t");
        Serial.println(z + prev_z);
      }
      
      // using rotation around z axis to control volume
  
      if ( (-2 < prev_z) && (prev_z < 2 ) ) // no rotation in between -2 < z < 2
      {
        base = 1;
        going_up = 0;
        going_down = 0;
        prev_z = z;
      }
          
      // Detecting a CW rotation big enough to elicit a volume change
      if ( (z - prev_z > 15) && base )
      {
        Serial.println("VolDown");
        prev_z = z;
        going_up = 1;
        going_down = 0;
        base = 0;
      }
  
      if ( (z - prev_z > 10 ) && going_up )
      {
        Serial.println("VolDown");
        prev_z = z;
      }
  
      if ( (z - prev_z < -15) && base )
      {
        Serial.println("VolUp");
        prev_z = z;
        going_up = 0;
        going_down = 1;
        base = 0;
      }
  
      if ( (z - prev_z < -10 ) && going_down )
      {
        Serial.println("VolUp");
        prev_z = z;
      }
     
      if (prev_z != 0 && !base)
        prev_z = z;
    }
}
