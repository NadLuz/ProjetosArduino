//Programa que faz piscar um LED a cada 1 segundo

void setup() {
  //Definição da porta onde será conectado o LED
  pinMode(7,OUTPUT);

}

void loop() {
  //comando que envia sinal alto para a porta
  digitalWrite(7,HIGH);
  //tempo de espera
  delay(1000);
  //comando que envia sinal baixo para a porta
  digitalWrite(7, LOW);
  //tempo de espera
  delay(1000);

}
