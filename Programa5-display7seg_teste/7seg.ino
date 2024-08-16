int SEG_A = 2;
int SEG_B = 3;
int SEG_C = 4;
int SEG_D = 5;
int SEG_E = 6;
int SEG_F = 7;
int SEG_G = 8;
int PONTO = 9;
int ATRASO = 150;
void setup() {
for (int pino = SEG_A; pino <= SEG_G; pino++) {
  pinMode(pino, OUTPUT);
}
}
void loop() {
  for (int pino = SEG_A; pino < SEG_G; pino++) {
    digitalWrite(pino, HIGH);
    if (pino > SEG_A)
    digitalWrite(pino - 1, LOW);
    else
    digitalWrite(SEG_F, LOW);
    delay(ATRASO);
  }
}