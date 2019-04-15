import serial

arduino = serial.Serial('/dev/ttyACM0', 9600)

cond = True
while cond:
    numero = raw_input("Numero del 0-9: ")
    if numero == 'close':
        cond = False
    else:
        arduino.write(numero)
        print arduino.readline()

arduino.close()
