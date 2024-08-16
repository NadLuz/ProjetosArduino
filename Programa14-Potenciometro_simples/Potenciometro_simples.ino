int valorpot = 0;
float luminosidade = 0;
void setup(){
  Serial.begin(9600); //inicia a serial
  pinMode (10, OUTPUT); //Define como saída
  pinMode (A5, INPUT); //Define como entrada
}
void loop(){
  valorpot = analogRead(5); //Lê o valor no pino
  //Converte e atribui para a variável o valor lido
  luminosidade = map (valorpot, 0, 1023, 0, 255);
  Serial.print("Valor lido do potenciômetro: ");
  //exibe o valor lido no monitor serial
  Serial.print(valorpot);
  Serial.print (" = Luminosidade: ");
  //exibe o valor convertido para luminosidade
  Serial.println (luminosidade);
  analogWrite (10, luminosidade);
}