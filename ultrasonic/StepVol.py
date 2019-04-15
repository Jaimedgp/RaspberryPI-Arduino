
from subprocess import check_output 
import serial
import alsaaudio

arduino = serial.Serial("/dev/ttyACM0", 9600)
old_data = 0
vol = 30

while True:
    data = int(arduino.readline())

    if data < 150:
        if data < old_data and vol != 0:
            vol -= 2
        elif data > old_data and vol != 100:
            vol += 2
        old_data = data

        line = check_output(["amixer", "-D", "pulse", "sset", "Master", str(vol)+"%"])
