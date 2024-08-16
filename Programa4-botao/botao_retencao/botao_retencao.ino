int valor;
int anterior = 0;
int estadoBotao = LOW;
void setup() {
  pinMode (2, OUTPUT); //led
  pinMode (5, INPUT); //botao
}

void loop() {
  valor = digitalRead(5);      
  if (valor == HIGH && anterior == LOW) {
    estadoBotao =! estadoBotao;
  }
  digitalWrite(2,estadoBotao);
  anterior = valor;
  delay(50);       
}