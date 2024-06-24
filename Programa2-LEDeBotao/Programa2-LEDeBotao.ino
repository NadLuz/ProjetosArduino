// definição das variáveis do programa
int botao;
int estadoAnterior = 0;
int estadoBotao = LOW;

void setup() {
  // definição da porta de saída
  pinMode (2,OUTPUT);
  // definição da porta de entrada
  pinMode (5,INPUT);
  
}

void loop() {
  // lê a informação na porta 5 e armazena na variável 'botao'
  botao = digitalRead(5);

  //se o botao estiver com nível HIGH e o valor anterior for LOW   
  if (botao == HIGH && estadoAnterior == LOW){
    // interte o valor do estadoBotao
    estadoBotao =! estadoBotao;
  }

  // escreve na porta 2 o valor que estiver em estadoBotao
  digitalWrite (2, estadoBotao);

  // escreve na variável estadoAnterior qual o valor em 'botao'
  estadoAnterior = botao;
  delay(50);

}
