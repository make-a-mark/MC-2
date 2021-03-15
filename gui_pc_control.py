import tkinter
from tkinter import ttk
from tkinter import *
from PIL import Image, ImageTk

import csv
from csv import reader

from tempfile import NamedTemporaryFile
import shutil

import serial
import time
import pyautogui

profiles_list = []
gestures_list = []
profile_file = r'C:/Users/markm/Desktop/Winter Quarter 2021/ECE M119/MC^2/Profiles/profiles.csv'
tempfile = NamedTemporaryFile('w+t', newline='', delete=False)

# open file in read mode
with open(profile_file) as profile_csv, tempfile:
    # pass the file object to reader() to get the reader object
    csv_reader = reader(profile_csv, delimiter=',')
    writer = csv.writer(tempfile, delimiter=',')
    rows = list(csv_reader)
    temp_rows = rows.copy()
    gestures_list = rows[1].copy()
    #print(rows)

profile_csv.close()
#print ("---------------")
#print (temp_rows)

#print (len(rows))
num_profiles = len(rows)//3
#print("number of profiles = " + str(num_profiles))

for row_info in rows:
    print (row_info)

for i in range(num_profiles):
    print(i)
    profiles_list.append(rows[3*i][0])

all_keyboard_options = ['\t', '\n', '\r', ' ', '!', '"', '#', '$', '%', '&', "'", '(',
')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',
'browserback', 'browserfavorites', 'browserforward', 'browserhome',
'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',
'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',
'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',
'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',
'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',
'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',
'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',
'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',
'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',
'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',
'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',
'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',
'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',
'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',
'command', 'option', 'optionleft', 'optionright']

root = Tk(className= "MC^2 Profile and Gesture Selector")
x_size = 1500
y_size = 1500
size = (str(x_size) + "x" + str(y_size))
root.geometry(size)

# Create a photoimage object of the image in the path
Arduino = Image.open("C:/Users/markm/Desktop/ArduinoNano.jpg")
#width = 285
#height = 510
#Arduino = Arduino.resize((width, height), Image.ANTIALIAS)

test = ImageTk.PhotoImage(Arduino)

label1 = tkinter.Label(image=test)
label1.image = test

# Position image
x_pos = 465
y_pos = 250
#x_pos = 250-width/2
#y_pos = 250-height/2


profile_select = StringVar(root)
profile_select.set(profiles_list[0]) # default value
 
############## SWIPE RIGHT TEXT AND BOXES ##############
ttk.Label(root, text = "Swipe Right Mapping :", 
          font = ("Times New Roman", 10)).place(x=1075, y=500) 

swipe_right_string = tkinter.StringVar() 
swipe_right_box = ttk.Combobox(root,width = 20, textvariable = swipe_right_string) 
swipe_right_box.place(x=1050, y=550)

############## CLOCKWISE ROTATION TEXT AND BOXES ##############
ttk.Label(root, text = "CW Rotation Mapping :", 
          font = ("Times New Roman", 10)).place(x=1075, y=1000)

cw_rotation_string = tkinter.StringVar() 
cw_rotation_box = ttk.Combobox(root,width = 20, textvariable = cw_rotation_string) 
cw_rotation_box.place(x=1050, y=1050)

############## SWIPE LEFT TEXT AND BOXES ##############

ttk.Label(root, text = "Swipe Left Mapping :", 
          font = ("Times New Roman", 10)).place(x=40, y=500) 

swipe_left_string = tkinter.StringVar() 
swipe_left_box = ttk.Combobox(root,width = 20, textvariable = swipe_left_string) 
swipe_left_box.place(x=20, y=550) 


############## COUNTER-CLOCKWISE ROTATION TEXT AND BOXES ##############

ttk.Label(root, text = "CCW Rotation Mapping :", 
          font = ("Times New Roman", 10)).place(x=20, y=1000)

ccw_rotation_string = tkinter.StringVar() 
ccw_rotation_box = ttk.Combobox(root,width = 20, textvariable = ccw_rotation_string) 
ccw_rotation_box.place(x=20, y=1050)

############## SWIPE UP TEXT AND BOXES ##############

ttk.Label(root, text = "Swipe Up Mapping :", 
          font = ("Times New Roman", 10)).place(x=575, y=50) 

swipe_up_string = tkinter.StringVar() 
swipe_up_box = ttk.Combobox(root,width = 20, textvariable = swipe_up_string) 
swipe_up_box.place(x=550, y=100) 

############## SWIPE DOWN TEXT AND BOXES ##############

ttk.Label(root, text = "Swipe Down Mapping :", 
          font = ("Times New Roman", 10)).place(x=550, y=1300) 

swipe_down_string = tkinter.StringVar() 
swipe_down_box = ttk.Combobox(root,width = 20, textvariable = swipe_down_string) 
swipe_down_box.place(x=525, y=1350) 

selected_profile = ""

def submit():
    global selected_profile
    #print(all_keyboard_options[swipe_right_box.current()])
    selected_profile = profile_select.get()
    print(selected_profile)
    root.destroy()


#def load_profile():
#    current_profile = profile_select.get()
#    profile_index = profiles_list.index(current_profile)
#    swipe_right_value = rows[2+(profile_index*3)][0]
#    mapped_index = all_keyboard_options.index(swipe_right_value)
#    swipe_right_box.current(mapped_index)


def save_profile():
    print("New swipe right map = " + str(all_keyboard_options[swipe_right_box.current()]) )
    print("Profile selected = " + str(profile_select.get()))

    current_profile = profile_select.get()
    profile_index = profiles_list.index(current_profile)
    print("Profile index = " + str(profile_index))
    swipe_right_value = rows[2+(profile_index*3)][0]
    swipe_left_value = rows[2+(profile_index*3)][1]

    print(temp_rows)
    temp_rows[2+(profile_index*3)][0] = all_keyboard_options[swipe_right_box.current()]
    temp_rows[2+(profile_index*3)][1] = all_keyboard_options[swipe_left_box.current()]
    temp_rows[2+(profile_index*3)][2] = all_keyboard_options[swipe_up_box.current()]
    temp_rows[2+(profile_index*3)][3] = all_keyboard_options[swipe_down_box.current()]
    temp_rows[2+(profile_index*3)][4] = all_keyboard_options[cw_rotation_box.current()]
    temp_rows[2+(profile_index*3)][5] = all_keyboard_options[ccw_rotation_box.current()]

    with open(profile_file, 'w') as write_file:
        writer = csv.writer(write_file, lineterminator = '\n')
        writer.writerows(temp_rows)

    write_file.close()
    #for row in temp_rows:
    #    writer.writerow(row)

profile_name_var=tkinter.StringVar()
new_profile_name = tkinter.Entry()
name_entered = False
current_profile = tkinter.StringVar(root)

def add_profile():
    global name_entered
    if not name_entered:
        global new_profile_name
        new_profile_name = tkinter.Entry(root, textvariable = profile_name_var)
        new_profile_name.place(x=20, y=400)
        enter_name = tkinter.Button(root, text = "Enter Name", command = add_profile).place(x=20, y=310)
        name_entered = True
    else:
        with open(profile_file, 'a+', newline='') as write_obj:
            global profile_button
            # Create a writer object from csv module
            csv_writer = csv.writer(write_obj)
            # Add contents of list as last row in the csv file
            append_profile = []
            profiles_list.append(new_profile_name.get())
            current_profile.set('')
            profile_button['menu'].delete(0, 'end')

            for prof in profiles_list:
                 profile_button['menu'].add_command(label=prof, command=tkinter._setit(current_profile, prof))

            profile_button = OptionMenu(root, profile_select, *profiles_list)
            profile_button.place(x=20,y=20)

            append_profile.append(new_profile_name.get())
            mappings = []
            mappings.append(all_keyboard_options[swipe_right_box.current()])
            mappings.append(all_keyboard_options[swipe_left_box.current()])
            mappings.append(all_keyboard_options[swipe_up_box.current()])
            mappings.append(all_keyboard_options[swipe_down_box.current()])
            mappings.append(all_keyboard_options[cw_rotation_box.current()])
            mappings.append(all_keyboard_options[ccw_rotation_box.current()])
            csv_writer.writerow(append_profile)
            csv_writer.writerow(gestures_list)
            csv_writer.writerow(mappings)
            #print(all_keyboard_options[keyboard_options.current()]) 
            #print(new_profile_name.get())
            
           
            # put in a list to append to csv file


def load_profile2(self):
    current_profile = profile_select.get()
    profile_index = profiles_list.index(current_profile)
    swipe_right_value = rows[2+(profile_index*3)][0]
    swipe_left_value = rows[2+(profile_index*3)][1]
    swipe_up_value = rows[2+(profile_index*3)][2]
    swipe_down_value = rows[2+(profile_index*3)][3]
    cw_rotation_value = rows[2+(profile_index*3)][4]
    ccw_rotation_value = rows[2+(profile_index*3)][5]
    mapped_swipe_right_index = all_keyboard_options.index(swipe_right_value)
    mapped_swipe_left_index = all_keyboard_options.index(swipe_left_value)
    mapped_swipe_up_index = all_keyboard_options.index(swipe_up_value)
    mapped_swipe_down_index = all_keyboard_options.index(swipe_down_value)
    mapped_cw_rotation_index = all_keyboard_options.index(cw_rotation_value)
    mapped_ccw_rotation_index = all_keyboard_options.index(ccw_rotation_value)
    swipe_right_box.current(mapped_swipe_right_index)
    swipe_left_box.current(mapped_swipe_left_index)
    swipe_up_box.current(mapped_swipe_up_index)
    swipe_down_box.current(mapped_swipe_left_index)
    cw_rotation_box.current(mapped_cw_rotation_index)
    ccw_rotation_box.current(mapped_ccw_rotation_index)

profile_button = OptionMenu(root, profile_select, *profiles_list, command = load_profile2)
#profile_button = OptionMenu(root, variable, *profiles, command=load_profile)
profile_button.place(x=20,y=20)

submit_button = tkinter.Button(root, text = "Submit", command = submit).place(x=1250, y=1250)
#load_profile_button = tkinter.Button(root, text = "Load Profile", command = load_profile).place(x=20, y=60)
save_profile_button = tkinter.Button(root, text = "Save Profile", command = save_profile).place(x=20, y=110)
add_profile_button = tkinter.Button(root, text = "Add Profile", command = add_profile).place(x=20, y=210)

label1.place(x=x_pos, y=y_pos)
# Adding combobox drop down list 
swipe_right_box['values'] = ('\\t', '\\n', '\\r', ' ', '!', '"', '#', '$', '%', '&', "'", '(',
')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',
'browserback', 'browserfavorites', 'browserforward', 'browserhome',
'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',
'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',
'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',
'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',
'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',
'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',
'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',
'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',
'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',
'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',
'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',
'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',
'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',
'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',
'command', 'option', 'optionleft', 'optionright') 

swipe_left_box['values'] = ('\\t', '\\n', '\\r', ' ', '!', '"', '#', '$', '%', '&', "'", '(',
')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',
'browserback', 'browserfavorites', 'browserforward', 'browserhome',
'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',
'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',
'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',
'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',
'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',
'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',
'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',
'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',
'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',
'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',
'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',
'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',
'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',
'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',
'command', 'option', 'optionleft', 'optionright') 

cw_rotation_box['values'] = ('\\t', '\\n', '\\r', ' ', '!', '"', '#', '$', '%', '&', "'", '(',
')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',
'browserback', 'browserfavorites', 'browserforward', 'browserhome',
'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',
'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',
'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',
'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',
'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',
'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',
'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',
'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',
'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',
'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',
'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',
'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',
'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',
'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',
'command', 'option', 'optionleft', 'optionright') 

ccw_rotation_box['values'] = ('\\t', '\\n', '\\r', ' ', '!', '"', '#', '$', '%', '&', "'", '(',
')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',
'browserback', 'browserfavorites', 'browserforward', 'browserhome',
'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',
'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',
'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',
'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',
'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',
'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',
'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',
'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',
'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',
'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',
'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',
'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',
'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',
'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',
'command', 'option', 'optionleft', 'optionright') 

swipe_up_box['values'] = ('\\t', '\\n', '\\r', ' ', '!', '"', '#', '$', '%', '&', "'", '(',
')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',
'browserback', 'browserfavorites', 'browserforward', 'browserhome',
'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',
'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',
'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',
'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',
'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',
'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',
'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',
'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',
'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',
'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',
'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',
'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',
'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',
'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',
'command', 'option', 'optionleft', 'optionright') 

swipe_down_box['values'] = ('\\t', '\\n', '\\r', ' ', '!', '"', '#', '$', '%', '&', "'", '(',
')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`',
'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',
'browserback', 'browserfavorites', 'browserforward', 'browserhome',
'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',
'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',
'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',
'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',
'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',
'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',
'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',
'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',
'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',
'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',
'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',
'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',
'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',
'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',
'command', 'option', 'optionleft', 'optionright') 


swipe_right_value = rows[2][0]
mapped_index = all_keyboard_options.index(swipe_right_value)
swipe_right_box.current(mapped_index)

cw_rotation_value = rows[2][0]
mapped_index = all_keyboard_options.index(cw_rotation_value)
cw_rotation_box.current(mapped_index)

swipe_left_value = rows[2][0]
mapped_index = all_keyboard_options.index(swipe_left_value)
swipe_left_box.current(mapped_index)


ccw_rotation_value = rows[2][0]
mapped_index = all_keyboard_options.index(ccw_rotation_value)
ccw_rotation_box.current(mapped_index)

swipe_up_value = rows[2][0]
mapped_index = all_keyboard_options.index(swipe_up_value)
swipe_up_box.current(mapped_index)

swipe_down_value = rows[2][0]
mapped_index = all_keyboard_options.index(swipe_down_value)
swipe_down_box.current(mapped_index)


root.mainloop()

arduino_serial = serial.Serial('com6', 9600)
time.sleep(2)

profile_index = profiles_list.index(selected_profile)
swipe_right_mapping  = rows[2+(profile_index*3)][0]
swipe_left_mapping  = rows[2+(profile_index*3)][1]
swipe_up_mapping  = rows[2+(profile_index*3)][2]
swipe_down_mapping  = rows[2+(profile_index*3)][3]
cw_rotation_mapping  = rows[2+(profile_index*3)][4]
ccw_rotation_mapping = rows[2+(profile_index*3)][5]


while 1:
      incoming = str (arduino_serial.readline())
      print (incoming)
      
      if 'Swipe Right' in incoming:
            pyautogui.press(swipe_right_mapping)
            print(swipe_right_mapping)
         
      if 'Swipe Left' in incoming:
            pyautogui.press(swipe_left_mapping)
            print(swipe_left_mapping)

      if 'Swipe Up' in incoming:
            pyautogui.press(swipe_up_mapping)
            print(swipe_up_mapping)

      if 'Swipe Down' in incoming:
            pyautogui.press(swipe_down_mapping)
            print(swipe_down_mapping)

      if 'CCW Rotation' in incoming:
            pyautogui.press(ccw_rotation_mapping)
            print(ccw_rotation_mapping)

      if 'CW Rotation' in incoming:
            pyautogui.press(cw_rotation_mapping)
            print(cw_rotation_mapping)

      if 'play' in incoming:
            pyautogui.press('playpause')
            print("playpause")

      if 'pause' in incoming:
            pyautogui.press('playpause')
            print("playpause")      