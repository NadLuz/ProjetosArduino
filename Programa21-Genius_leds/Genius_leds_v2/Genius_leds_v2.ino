// Define os pinos dos LEDs
int led1 = 4;
int led2 = 5;
int led3 = 6;

// Define os pinos dos botões
int button1 = 8;
int button2 = 9;
int button3 = 10;
// Define o pino do buzzer
int buzzer = 11;

// Define a sequência de cores a ser memorizada
int sequence[] = {led1, led2, led3};
int sequenceLength = 3;
// Define uma variável para armazenar a sequência atual
int currentSequence[3];
int currentSequenceLength = 0;
// Define uma variável para rastrear o estado do jogo
bool gameOver = false;

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Configura os pinos dos botões como entrada
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);  
  // Configura o pino do buzzer como saída
  pinMode(buzzer, OUTPUT);  
  // Inicializa a comunicação serial
  Serial.begin(9600);  
  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(0));
}

void loop() {
  // Se o jogo estiver em andamento, exibe a sequência atual
  if (!gameOver) {
    displaySequence();    
    // Espera um momento antes de aceitar entradas do jogador
    delay(500);    
    // Aguarda o jogador pressionar os botões na sequência correta
    for (int i = 0; i < sequenceLength; i++) {
      // Aguarda o jogador pressionar o botão correspondente
      int buttonPressed = waitForButtonPress();      
      // Verifica se o botão pressionado é o correto
      if (buttonPressed != sequence[i]) {
        gameOver = true;
        break;
      }
    }
    // Se o jogador tiver pressionado a sequência corretamente, adiciona um novo LED à sequência
    if (!gameOver) {
      addRandomLed();
    }
  }
  // Se o jogo acabou, toca uma sequência de sons e espera o jogador reiniciar o jogo
  else {
    playGameOverTune();
    waitForRestart();
  }
}

// Exibe a sequência atual de LEDs
void displaySequence() {
  for (int i = 0; i < currentSequenceLength; i++) {
    digitalWrite(currentSequence[i], HIGH);
    delay(500);
    digitalWrite(currentSequence[i], LOW);
    delay(100);
  }
}

// Espera o jogador pressionar um botão e retorna o pino correspondente
int waitForButtonPress() {
  while (true) {
    // Verifica se o botão 1 foi pressionado
    if (digitalRead(button1) == LOW) {
      playTone(262, 100);
      return button1;
    }    
    // Verifica se o botão 2 foi pressionado
    if (digitalRead(button2) == LOW) {
      playTone(294, 100);
      return button2;
    }
        // Verifica se o botão 3 foi pressionado
    if (digitalRead(button3) == LOW) {
      playTone(330, 100);
      return button3;
    }
  }
}

// Adiciona um novo LED à sequência atual de forma aleatória
void addRandomLed() {
  int newLed = sequence[random(0, sequenceLength)];
  currentSequence[currentSequenceLength++] = newLed;
}

// Toca uma sequência de sons para indicar que o jogo acabou
void playGameOverTune() {
  for (int i = 0; i < 3; i++) {
    playTone(262, 100);
    playTone(196, 100);
  }
  playTone(131, 200);
}

// Espera o jogador pressionar o botão de reinício
void waitForRestart() {
  while (digitalRead(button1) == HIGH) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    
    delay(500);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
   
    delay(500);
  }  
  // Reinicia o jogo
  currentSequenceLength = 0;
  gameOver = false;
}

// Toca um tom no buzzer pelo tempo especificado
void playTone(int frequency, int duration) {
  tone(buzzer, frequency, duration);
  delay(duration);
  noTone(buzzer);
} 