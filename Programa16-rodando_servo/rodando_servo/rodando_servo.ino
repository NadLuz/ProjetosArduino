//insere biblioteca
#include <Servo.h> 
//Cria um objeto Servo
Servo servo; 
//Define o pino do potenciômetro
const int pot = A0;
//Define variavel para o valor
int potValor;

void setup (){
  // Anexa o objeto Servo ao pino do servo
  servo.attach(3);
  //inicia o monitor serial
  Serial.begin(9600); 
}

void loop (){
  //lê o valor do potenciometro
  potValor = analogRead(pot);
  //converte o valor da variável para o servo (0 á 180)
  int servoPosition = map(potValor, 0, 1023, 180, 0);
  //move o servo para a nova posição
  servo.write(servoPosition);
  //escreve no monitor serial
  Serial.print("Ângulo atual: ");
  Serial.println(servoPosition);
  //espera um momento antes de ler novamente
  delay(15);
}