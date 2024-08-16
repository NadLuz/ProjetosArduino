// Define o pino do LDR
int LDR = A0;
// Define o pino do buzzer
int buzzer = 5;

void setup() {
  // Configura o pino do buzzer como saída
  pinMode(buzzer, OUTPUT);
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lê a tensão no pino do LDR
  leitura = analogRead(LDR);
  // Escreve a leitura na porta serial
  Serial.println(leitura);
  // Calcula a frequência em uma escala de 100 a 1000 Hz
  int frequencia = map(leitura, 0, 1023, 100, 1000);
  // Calcula a duração em uma escala de 10 a 500 ms
  int tempo = map(leitura, 0, 1023, 10, 500);  
  // Gera o som no buzzer com base na frequência e duração calculadas
  tone(buzzer, frequencia, tempo);
  // Aguarda um momento antes de realizar a próxima leitura
  delay(10);
}
