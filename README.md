# MC-2
MC^2 - The Microcontroller Music Controller
A smart, more interactive PC music controller using an Arduino 33 BLE Sense
ECE M119 Fundamentals of Embedded Networked Systems Group Project

## Team Members
Mark Andal
Andrew Lucchesi
Evan Snyder

## Project Proposal
[Initial Project Proposal] (https://docs.google.com/document/d/1gUU2CRSV_VKq6Mz_r3Ywr8m3B1aAN7H2Y15-eDvBMcA/edit?usp=sharing)

## Libraries Necessary
### On Arduino:
- Arduino_APDS9960.h (Gesture Sensor)
- Arduino_LSM9DS1 (IMU)

### On Python:
- pyautogui
- serial

## Features
###Gesture Control:
* Swipe Right = Next Track
* Swipe Left = Prev Track
* Swipe Up/Down = Play/Pause

###Volume Control:
* Volume Up = Rotate CCW
* Volume Down = Rotate CW

## How to Run
### On Windows:
1. Upload code to Arduino 33 BLE Sense over USB
2. Make sure Python installed + pyautogui and serial libraries installed
3. Use Device Manager if necessary to check the usb / serial port and change port in pc_control.py script
4. Using command prompt, navigate to directory with pc_control.py
5. Type "python pc_control.py"
6. Switch to whatever application you want to control, example: Spotify.
7. Use the features, like gesture control to control your music!

## Acknowledgements
Machine Learning Process for sound processing:
https://eloquentarduino.github.io/2020/08/better-word-classification-with-arduino-33-ble-sense-and-machine-learning/
