// Define o pino do LED
int pinoLED = 9;
// Define o pino do LDR
int pinoLDR = A0;

void setup(){
  // Configura o pino do LED como saída
  pinMode(pinoLED, OUTPUT);
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop(){
  // Lê a tensão no pino do LDR
  int leitura = analogRead(pinoLDR);
  // Escreve a leitura na porta serial
  Serial.print("Valor lido: ");
  Serial.println(leitura);
  // Calcula a luminosidade em uma escala de 0 a 255
  int brilho = map(leitura, 0, 1023, 0, 255);
  // Define o brilho do LED com base na luminosidade medida
  analogWrite(pinoLED, brilho);  
  // Aguarda um momento antes de realizar a próxima leitura
  delay(10);
}