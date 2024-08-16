// Definição de variáveis
#define buz 12
#define ledG 2
#define ledR 3
#define ledY 4
#define ledB 5
#define pushG 6
#define pushR 7
#define pushY 8
#define pushB 9

void setup() {
  for (int pino = pushG; pino <= pushB; pino ++){
    pinMode(pino, INPUT_PULLUP);
  }
  for (int LED = ledG; LED <= ledB; LED ++){
    pinMode(LED, OUTPUT);
  }
  pinMode(buz, OUTPUT);
  randomSeed(digitalRead(0)); //Valores aleatórios quando o jogo é reiniciado
}

void loop() {
  int inicio = 1; // Botão de iniciar
  // Inicia o jogo quando o botão do led verde for pressionado
  while(inicio!=0){ // Como os botão estão ligados em portas pullup, quando eles são pressionados, o valor de retorno é 0
    inicio = digitalRead(pushG); // Lê o botão
    for (int LED = ledG; LED <= ledB; LED ++){
      digitalWrite(LED, HIGH);
    }
  }
  for (int LED = ledG; LED <= ledB; LED ++){
    digitalWrite(LED, LOW);
  }    
  delay(1000); // Pausa de 1 segundo

  int acertou = 1; // Variável que determina se o jogador acertou ou não
  int luzes[200]; // Variável que guarda a sequência de cores
  int quant = 0; // Quantidade de cores na sequência
  int pont = 0; // Pontuação do jogador
  
  while(acertou == 1){ // Enquanto o jogador continuar acertando...            
    luzes[quant] = random(1, 5); // Escolhe aleatoriamente qual luz será a próxima a acender
    quant = quant + 1; // Adiciona 1 a quantidade de cores na sequência    
    for(int i = 0; i < quant; i++){ // Loop para acender a sequência de luzes uma a uma
      if(luzes[i] == 1){ // Verifica se é esta a luz que deve acender
        digitalWrite(ledG, HIGH); // Se sim, liga o led correspondente
        tone(buz, 262, 500); // Toca o buzzer na frequência pré-determinada para essa cor
        delay(500);
        digitalWrite(ledG, LOW); // Depois de um tempo, apaga a luz
        delay(200);
      } // A mesma lógica é implementada para as demais luzes
      
      if(luzes[i] == 2){
        digitalWrite(ledR, HIGH);
        tone(buz, 294, 500);
        delay(500);
        digitalWrite(ledR, LOW);
        delay(200);
      }
      if(luzes[i] == 3){
        digitalWrite(ledY, HIGH);
        tone(buz, 330, 500);
        delay(500);
        digitalWrite(ledY, LOW);
        delay(200);
      }
      if(luzes[i] == 4){
        digitalWrite(ledB, HIGH);
        tone(buz, 349, 500);
        delay(500);
        digitalWrite(ledB, LOW);
        delay(200);
      }
    }

    int aux = 0; // Variável do led que aciona dentro do vetor
    int terminou = 0; // Variável que verifica se o jogador terminou

    while(terminou == 0 && acertou == 1){ // Enquanto ainda faltarem luzes para serem pressionadas e o jogador ainda não tiver perdido...
      int pg = digitalRead(pushG); // Lê o botões de cada luz
      int pr = digitalRead(pushR);
      int py = digitalRead(pushY);
      int pb = digitalRead(pushB);
      if(pg == 0){ // Se o botão dessa luz for pressionado...
        digitalWrite(ledG, HIGH); // O led acende
        tone(buz, 262, 500); // O buzzer toca
        if(luzes[aux] == 1){ // Verifica se o jogador acertou a luz correta
          aux++; // Se sim, a próxima luz é apontada
        }
        else{
          acertou = 0; // Se não, o jogador errou
        }
        while(pg == 0){pg = digitalRead(pushG);} // Enquanto o jogador estiver pressionando o botão da luz, o programa estaciona nesse ponto
        delay(500);
        digitalWrite(ledG, LOW); // A luz se apaga
        delay(500);
      } // A mesma lógica é implementada para todas as luzes

      if(pr == 0){
        digitalWrite(ledR, HIGH);
        tone(buz, 294, 500);
        if(luzes[aux] == 2){
          aux++;
        }
        else{
          acertou = 0;
        }
        while(pr == 0){pr = digitalRead(pushR);}
        delay(500);
        digitalWrite(ledR, LOW);
        delay(500);
      }
      if(py == 0){
        digitalWrite(ledY, HIGH);
        tone(buz, 330, 500);
        if(luzes[aux] == 3){
          aux++;
        }
        else{
          acertou = 0;
        }
        while(py == 0){py = digitalRead(pushY);}
        delay(500);
        digitalWrite(ledY, LOW);
        delay(500);
      }
      if(pb == 0){
        digitalWrite(ledB, HIGH);
        tone(buz, 349, 500);
        if(luzes[aux] == 4){
          aux++;
        }
        else{
          acertou = 0;
        }
        while(pb == 0){pb = digitalRead(pushB);}
        delay(500);
        digitalWrite(ledB, LOW);
        delay(500);
      }
      if(aux >= quant){ // Se o jogador já terminou a sequência...
        terminou = 1;
        pont++; // Sua pontuação sobe
      }
    }
  }
  // Se o jogador errou...
  tone(buz, 415, 3000); // O buzzer toca numa frequência diferente das luzes
  delay(3000);
}