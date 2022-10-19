from tkinter import N
import serial
def f1(num):
    p='/dev/ttyACM'+str(num);
    ser1 = serial.Serial('/dev/ttyACM0', 115600, timeout=1)
    ser1.reset_input_buffer()
    while True:
        if ser1.in_waiting > 0:
            line = ser1.readline().decode('utf-8').rstrip()
            print(line)
            break



for i in range(4):
    f1(i)
