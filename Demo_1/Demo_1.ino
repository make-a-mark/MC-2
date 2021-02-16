#include <Arduino_APDS9960.h>
#include <Arduino_LSM9DS1.h>

#include "Mic.h"
#include "Classifier.h"

// tune as per your needs
#define SAMPLES 64
#define GAIN (1.0f/50)
#define SOUND_THRESHOLD 1000

/* Variable Initialization */
float prev_z = 0;
int going_up = 0;
int going_down = 0;
int base = 1;

float x, y, z;

int debug_flag = 0;

float features[SAMPLES];
Mic mic;
Eloquent::ML::Port::SVM clf;


void setup() 
{
    Serial.begin(115200);
    while (!Serial);
    PDM.onReceive(onAudio);
    mic.begin();
    delay(3000);

    if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
    }

    if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
    }
}


void loop() 
{
    if (recordAudioSample()) 
    {
        if (debug_flag)
          Serial.print("You said: ");
        Serial.println(clf.predictLabel(features));
        //delay(1000);
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


/**
 * PDM callback to update mic object
 */
void onAudio() {
    mic.update();
}


/**
 * Read given number of samples from mic
 */
bool recordAudioSample() {
    if (mic.hasData() && mic.data() > SOUND_THRESHOLD) {

        for (int i = 0; i < SAMPLES; i++) {
            while (!mic.hasData())
                delay(1);

            features[i] = mic.pop() * GAIN;
        }

        return true;
    }

    return false;
}
