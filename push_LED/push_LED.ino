// Práctica encender LED con botón pulsador y luego apagar LED con el mismo
//boton pulsador
const int LED =13;
const int BOTON = 3;
const int LED1 = 12;
int val = 0; //val se emplea para almacenar el estado del boton
int state = 0; // 0 LED apagado, mientras que 1 encendido
int old_val = 0; // almacena el antiguo valor de val
void setup(){  // definir si la variable es de entrada // o salida.
 pinMode(LED,OUTPUT); // establecer que el pin digital es una señal de salida
 pinMode(BOTON,INPUT); // y BOTON como señal de entrada
}
void loop() {       // loop = realice un lazo continuamente
val= digitalRead(BOTON); // lee el estado del Boton
if ((val == HIGH) && (old_val == LOW)){
  for (int i=0; i<256; i++){
    analogWrite(LED, i);
    delay(10);
  }
  digitalWrite(LED1, HIGH);
  delay(10);
  if(state != 5) {
    state++;
  } else {
    state = 0;
  }
delay(10);
}

old_val = val; // valor del antiguo estado
//analogWrite(LED, state*51);
}
