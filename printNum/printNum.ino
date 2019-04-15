const int LEDs[2][4] = {{0, 1, 2, 3}, 
            {10, 11, 12, 13}};

int num[][2][4] = {{{0,1,1,1}, {1,1,1,1}}, // 0
           {{0,0,0,1}, {0,0,1,0}}, // 1
           {{1,0,1,1}, {1,1,0,0}}, // 2
           {{1,0,1,1}, {0,1,1,0}}, // 3
           {{1,1,0,1}, {0,0,1,0}}, // 4
           {{1,1,1,0}, {0,1,1,0}}, // 5
           {{1,1,1,0}, {1,1,1,0}}, // 6
           {{0,0,1,1}, {0,0,1,0}}, // 7
           {{1,1,1,1}, {1,1,1,0}}, // 8
           {{1,1,1,1}, {0,0,1,0}}}; //9

void setup(){  // definir si la variable es de entrada // o salida.
  Serial.begin(9600); //Inicializo el puerto serial a 9600 baudios
  for (int i=0; i<2;i++) {
    for (int j=0; j<4; j++){
      pinMode(LEDs[i][j], OUTPUT); // establecer que el pin digital es una señal de salida
    }
  }
}

void loop() {
  if (Serial.available()) {
    int c = Serial.read(); //Guardamos la lectura en una variable char
    c = c - 48;
    Serial.println(c);
    for (int i=0; i<2;i++) {
      for (int j=0; j<4; j++){
        digitalWrite(LEDs[i][j], num[c][i][j]);
      }
    }
    delay(1000);
  }
}
