import serial
if __name__ == '__main__':
    p='/dev/ttyACM0';
    ser1 = serial.Serial('/dev/ttyACM0', 115600, timeout=1)
    ser1.reset_input_buffer()
    while True:
        if ser1.in_waiting > 0:
            line = ser1.readline().decode('utf-8').rstrip()
            print(line)
            p=p[:-1]+str(int(p[-1])+1)
            break

    ser2 = serial.Serial('/dev/ttyACM1', 9600, timeout=1)
    ser2.reset_input_buffer()
    while True:
        if ser2.in_waiting > 0:
            line = ser2.readline().decode('utf-8').rstrip()
            print(line)
            break

    ser3 = serial.Serial('/dev/ttyACM2', 115600, timeout=1)
    ser3.reset_input_buffer()
    while True:
        if ser3.in_waiting > 0:
            line = ser3.readline().decode('utf-8').rstrip()
            print(line)
            break

    ser4 = serial.Serial('/dev/ttyACM3', 19200, timeout=1)
    ser4.reset_input_buffer()
    while True:
        if ser4.in_waiting > 0:
            line = ser4.readline().decode('utf-8').rstrip()
            print(line)
            break