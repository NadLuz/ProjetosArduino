#include <Servo.h>
Servo servo1;
Servo servo2;

float x, y;
byte eixoX = A0;      // pino analógico do eixo X
byte eixoY = A2; 


void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(eixoX, INPUT);                // entrada leitura eixo X joystick
  pinMode(eixoY, INPUT);
  servo1.attach(9);
  
  servo2.attach(7);
  
  Serial.begin(9600);
}

void loop() {
  
  x = analogRead(eixoX); 
  int posicao1 = map(x, 0, 1023, 105, 85);// faz a leitura do eixo x (0 a 1023) - analógico 
  servo1.write(posicao1);
  y = analogRead(eixoY);
  int posicao2 = map(y, 0, 1023, 140, 100);// faz a leitura do eixo x (0 a 1023) - analógico 
  servo2.write(posicao2);
  Serial.println(x);
  Serial.println(posicao1);
  Serial.println(" ");
  Serial.println(y);
  Serial.println(posicao2);
  
  servo1.write(posicao1);
  servo2.write(posicao2);
  delay(50);    
  
}