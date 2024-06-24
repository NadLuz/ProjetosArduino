int botao;
int estadoAnterior = 0;
int estadoBotao = LOW;

void setup() {
  pinMode (2,OUTPUT);
  pinMode (5,INPUT);
  
}

void loop() {
  botao = digitalRead(5);
  if (botao == HIGH && anterior == LOW){
    estadoBotao =! estadoBotao;
  }

  digitalWrite (2, estadoBotao);

  anterior = valor;
  delay(50);

}
