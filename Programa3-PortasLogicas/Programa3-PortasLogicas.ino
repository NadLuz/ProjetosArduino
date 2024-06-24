// Programa que simula o funcionamento
// das portas lógicas 'E' e 'OU'

// variáveis
int b1, b2, b3, b4;

void setup() {
  //definindo as portas de saída
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);

  //definindo as portas de entrada
  pinMode(8,INPUT);
  pinMode(6,INPUT);
  pinMode(4,INPUT);
  pinMode(2,INPUT);

}

void loop() {
  // lê o valor na porta e armazena na variável
  b1 = digitalRead(8);
  b2 = digitalRead(6);
  b3 = digitalRead(4);
  b4 = digitalRead(2);

  // botões para a lógica 'E'
  if (b1 == HIGH && b2 == HIGH){
    digitalWrite(10,HIGH);
  }else {
    digitalWrite (10,LOW);
  }
  delay(50);

  // botões para a lógica 'OU'
  if (b3 == HIGH || b4 == HIGH){
    digitalWrite(12,HIGH);
  }else {
    digitalWrite (12,LOW);
  }
  delay(50);
}
