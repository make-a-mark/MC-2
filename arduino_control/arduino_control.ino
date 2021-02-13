#include <Arduino_APDS9960.h>
#include <Arduino_LSM9DS1.h>

/* Variable Initialization */
float prev_z = 0;
int going_up = 0;
int going_down = 0;
int base = 1;

float x, y, z;

int debug_flag = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
  }

  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  //APDS.setGestureSensitivity(80);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  
}
void loop() {
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
      Serial.println("VolUp");
      prev_z = z;
      going_up = 1;
      going_down = 0;
      base = 0;
    }

    if ( (z - prev_z > 10 ) && going_up )
    {
      Serial.println("VolUp");
      prev_z = z;
    }

    if ( (z - prev_z < -15) && base )
    {
      Serial.println("VolDown");
      prev_z = z;
      going_up = 0;
      going_down = 1;
      base = 0;
    }

    if ( (z - prev_z < -10 ) && going_down )
    {
      Serial.println("VolDown");
      prev_z = z;
    }
   
    if (prev_z != 0 && !base)
      prev_z = z;
  }
}
