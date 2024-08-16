#include <Servo.h> // inclui a biblioteca

// Cria um objeto Servo
Servo servo;

// Define a posição inicial do servo
int servoPosition = 90;

void setup() {
  // Configura os pinos dos botões como entrada
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  // Anexa o objeto Servo ao pino do servo
  servo.attach(9);
  // Define a posição inicial do servo
  servo.write(servoPosition);
}

void loop() {
  // Lê o estado dos botões
  int btn1 = digitalRead(3);
  int btn2 = digitalRead(5);

  // Verifica se o botão 1 foi pressionado
  if (btn1 == HIGH) {
    // Aumenta a posição do servo em 1 grau
    servoPosition++;
    // Limita a posição do servo entre 0 e 180 graus
    servoPosition = min(max(servoPosition, 0), 180);
    // Move o servo para a nova posição
    servo.write(servoPosition);
    // Espera um momento para evitar a repetição rápida do movimento
    delay(50);
  }

  // Verifica se o botão 2 foi pressionado
  if (btn2 == HIGH) {
    // Diminui a posição do servo em 1 grau
    servoPosition--;
    // Limita a posição do servo entre 0 e 180 graus
    servoPosition = min(max(servoPosition, 0), 180);
    // Move o servo para a nova posição
    servo.write(servoPosition);
    // Espera um momento para evitar a repetição rápida do movimento
    delay(50);
  }
}
