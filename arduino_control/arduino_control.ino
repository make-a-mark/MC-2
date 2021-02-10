#include <Arduino_APDS9960.h>

void setup() {
  Serial.begin(9600);
  //while (!Serial);

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
  }

  // for setGestureSensitivity(..) a value between 1 and 100 is required.
  // Higher values makes the gesture recognition more sensible but less accurate
  // (a wrong gesture may be detected). Lower values makes the gesture recognition
  // more accurate but less sensible (some gestures may be missed).
  // Default is 80
  //APDS.setGestureSensitivity(80);

  Serial.println("Detecting gestures ...");
}
void loop() {
  if (APDS.gestureAvailable()) {
    // a gesture was detected, read and print to serial monitor
    int gesture = APDS.readGesture();

    switch (gesture) {
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
}
