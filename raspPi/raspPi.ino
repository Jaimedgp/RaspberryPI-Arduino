int green = 13;
int red = 12;
int blue = 11;

int statusG = 0;
int statusR = 0;
int statusB = 0;

void setup () {
   pinMode(green, OUTPUT); //green 13 como salida
   pinMode(red, OUTPUT);
   pinMode(blue, OUTPUT);
   Serial.begin(9600); //Inicializo el puerto serial a 9600 baudios
}

void loop () {
   if (Serial.available()) { //Si está disponible
      char c = Serial.read(); //Guardamos la lectura en una variable char
      if (c == 'G') { //Si es una 'H', enciendo el green
         statusG = 1- statusG;
         digitalWrite(green, statusG);
      } else if (c == 'R') { //Si es una 'L', apago el green
         statusR = 1- statusR;
         digitalWrite(red, statusR);
      } else if (c == 'B') { //Si es una 'L', apago el green
         statusB = 1- statusB;
         digitalWrite(blue, statusB);
      }
   }
}
