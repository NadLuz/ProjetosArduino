
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8; 
int leituraLDR = 0;
int leituraBotao;

void setup() {
  pinMode(pinoLDR, INPUT);//configura como entrada
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  // le o valor de tensão no pino do LDR
  leituraLDR = analogRead(pinoLDR);
  // le o estado do botao
  leituraBotao = digitalRead(pinoBotao);
  
  if (leituraLDR <= 512) {// Se existir um obstáculo
    tone(pinoBuzzer, 1000); // aciona o buzzer
  }
  else if (leituraBotao == LOW) { //senão e botão estiver pressionado
    noTone(pinoBuzzer); // desliga o buzzer
  }
    delay(100);//aguarda 100 milissegundos para uma nova leitura
}
