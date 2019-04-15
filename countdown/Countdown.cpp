const int LEDs[2][4] = {{0, 2, 12, 13}, 
						{1, 3, 11, 10}};

int num[][2][4] = {{{0,0,0,0}, {0,0,0,1}}, // 0
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
	for (int i=0; i<2;i++) {
		for (int j=0; j<4; j++){
			pinMode(LEDs[i][j], OUTPUT); // establecer que el pin digital es una señal de salida
		}
	}
}

void loop() {
	for (int a=0;a<num.lenght;a++) {
		for (int i=0; i<2;i++) {
			for (int j=0; j<4; j++){
				digitalWrite(LEDs[i][j], num[a][i][j]);
			}
		}
    delay(1000);
	}
}