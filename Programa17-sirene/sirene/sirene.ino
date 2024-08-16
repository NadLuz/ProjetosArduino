//define o pino do buzzer
int buzzer = 6;
//define as frequencias
int freq1 = 1000;
int freq2 = 2000;
//define os tempos
int time1 = 200;
int time2 = 400;

void setup()
{
  //configura o pino como saída
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  //Reproduzir o som da sirene da polícia
  tone(buzzerPin, freq1);
  delay(time1);
  //função que interrompe a reprodução do som
  noTone(buzzerPin);
  delay(time2);
  tone(buzzerPin, freq2);
  delay(time1);
  noTone(buzzerPin);
  delay(time2);
}