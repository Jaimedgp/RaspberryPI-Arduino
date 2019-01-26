from subprocess import check_output 
import serial
import alsaaudio

arduino = serial.Serial("/dev/ttyACM0", 9600)

while True:
    data = float(arduino.readline())

    if data < 100:
        vol = data

        line = check_output(["amixer", "-D", "pulse", "sset", "Master", str(vol)+"%"])
        print "Volumen: "+str(data)
