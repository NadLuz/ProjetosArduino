const int pino_a = 12;
const int pino_b = 9;
const int pino_c = 10;
const int pino_d = 11;

const int pino_botao = 2 ; //botão de sorteio
int  leitura_botao, resultado; //leitura do botão 

void setup() {
  Serial.begin(9600);
  //Configuraçao dos pinos do código BCD
  pinMode(pino_a, OUTPUT); //digito menos significativo
  pinMode(pino_b, OUTPUT);
  pinMode(pino_c, OUTPUT);
  pinMode(pino_d, OUTPUT); //digito mais significativo
  pinMode(pino_botao, INPUT_PULLUP); //botão de sorteio
}

void loop() {
  leitura_botao = digitalRead(pino_botao); //ler botão
  if (leitura_botao == LOW) {// se o botão foi pressionado
    delay(150); // delay de 150 ms para que o código não fique sorteando varios números
    resultado = random(1, 9);//sortear valores de 1 a 8
    switch (resultado) { // verifica em qual case o valor da variável resultado é igual
      case 1: //aciona os pinos para o dígito 1, quando o resultado for igual a 1
        digitalWrite(pino_a, HIGH);
        digitalWrite(pino_b, LOW);
        digitalWrite(pino_c, LOW);
        digitalWrite(pino_d, LOW);
      break; // encerra o switch

      case 2: //aciona os pinos para o dígito 2, 
      //quando o resultado for igual a 2
        digitalWrite(pino_a, LOW);
        digitalWrite(pino_b, HIGH);
        digitalWrite(pino_c, LOW);
        digitalWrite(pino_d, LOW);
      break; // encerra o switch

      case 3: //aciona os pinos para o dígito 3, 
      //quando o resultado for igual a 3
        digitalWrite(pino_a, HIGH);
        digitalWrite(pino_b, HIGH);
        digitalWrite(pino_c, LOW);
        digitalWrite(pino_d, LOW);
      break; // encerra o switch

      case 4: /*aciona os pinos para o dígito 4, 
      quando o resultado for igual a 4*/
        digitalWrite(pino_a, LOW);
        digitalWrite(pino_b, LOW);
        digitalWrite(pino_c, HIGH);
        digitalWrite(pino_d, LOW);
      break; // encerra o switch

      case 5:  /*aciona os pinos para o dígito 5, 
      quando o resultado for igual a 5*/
        digitalWrite(pino_a, HIGH);
        digitalWrite(pino_b, LOW);
        digitalWrite(pino_c, HIGH);
        digitalWrite(pino_d, LOW);
      break; // encerra o switch

      case 6: /*aciona os pinos para o dígito 6, 
      quando o resultado for igual a 6*/
        digitalWrite(pino_a, LOW);
        digitalWrite(pino_b, HIGH);
        digitalWrite(pino_c, HIGH);
        digitalWrite(pino_d, LOW);
      break; // encerra o switch

      case 7: /*aciona os pinos para o dígito 7, 
      quando o resultado for igual a 7*/
        digitalWrite(pino_a, HIGH);
        digitalWrite(pino_b, HIGH);
        digitalWrite(pino_c, HIGH);
        digitalWrite(pino_d, LOW);
      break; // encerra o switch

      case 8: /*aciona os pinos para o dígito 8, 
      quando o resultado for igual a 8*/
        digitalWrite(pino_a, LOW);
        digitalWrite(pino_b, LOW);
        digitalWrite(pino_c, LOW);
        digitalWrite(pino_d, HIGH);
      break; // encerra o switch
    }
  }
}
