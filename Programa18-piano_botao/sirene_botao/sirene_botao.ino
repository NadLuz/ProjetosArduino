// Definir os pinos dos botões e do buzzer
int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int buzzer = 9;

void setup(){
  //Configurar os pinos dos botões como entrada
  //  pinMode(button1Pin, INPUT_PULLUP);
  pinMode (btn1, INPUT);
  pinMode (btn2, INPUT);
  pinMode (btn3, INPUT);
  //Configurar o pino do buzzer como saída
  pinMode(buzzer, OUTPUT);
  //Configurar os pinos dos LEDS
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
}

void loop(){
  // Verificar se o botão 1 foi pressionado
  if (digitalRead(btn1) == LOW) {
    // Reproduzir um som agudo
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
    digitalWrite (11, HIGH);
    delay(500);
    digitalWrite (11, LOW);
  }

  // Verificar se o botão 2 foi pressionado
  if (digitalRead(button2Pin) == LOW) {
    // Reproduzir um som médio
    tone(buzzerPin, 500);
    delay(500);
    noTone(buzzerPin);
    digitalWrite (12, HIGH);
    delay(500);
    digitalWrite (12, LOW);
  }

  // Verificar se o botão 3 foi pressionado
  if (digitalRead(button3Pin) == LOW) {
    // Reproduzir um som grave
    tone(buzzerPin, 200);
    delay(500);
    noTone(buzzerPin);
    digitalWrite (13, HIGH);
    delay(500);
    digitalWrite (13, LOW);
  }
}