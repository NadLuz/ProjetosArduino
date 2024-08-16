#include <Servo.h>

Servo s;
int valor;
void setup (){
  s.attach(9);
  pinMode(2, INPUT);
  digitalWrite (2, HIGH);
  pinMode(4, INPUT);
  digitalWrite (4, HIGH);
  Serial.begin(9600);
}
void loop (){
  Serial.write(valor);

  valor = digitalRead (2);
  if (valor !=1){
    s.write(50);
    delay(15);
  }
  valor = digitalRead(4);
  if (valor!=1){
    s.write (20);
    delay(15);
  }
}