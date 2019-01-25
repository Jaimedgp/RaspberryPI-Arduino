import serial 

arduino = serial.Serial('/dev/ttyACM0', 9600)

print "Starting"

cond = True
while cond:
    comando = raw_input("Introduce un comando: ")
    if comando == 'close':
        cond = False
    elif comando == 'G':
        print "VERDE!"
    elif comando == 'R':
        print "ROJO!"
    elif comando == "B":
        print "AZUL!"
    arduino.write(comando)
arduino.close()
