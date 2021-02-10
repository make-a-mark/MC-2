import serial
import time
import pyautogui

arduino_serial = serial.Serial('com6', 9600)
time.sleep(2)


while 1:
      incoming = str (arduino_serial.readline())
      print (incoming)
      
      if 'NextTrack' in incoming:
            pyautogui.press('nexttrack')
            print("next")
         
      if 'PrevTrack' in incoming:
            pyautogui.press('prevtrack')
            print("prev")

      if 'playpause' in incoming:
            pyautogui.press('playpause')
            print("playpause")





	 
	 
