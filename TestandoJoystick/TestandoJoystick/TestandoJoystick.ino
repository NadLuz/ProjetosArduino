#define eixoX A2
#define eixoY A1
#define btn  2

void setup() {
  pinMode(eixoX, INPUT);
  pinMode(eixoY, INPUT);
  pinMode(btn, INPUT_PULLUP); //resistor interno
  //inicia o monitor serial
  Serial.begin(9600);
}

void loop() {

  int valorEixoX = analogRead(eixoX);
  int valorEixoY = analogRead(eixoY);
  bool statusBtn = digitalRead(btn);

  Serial.print("Valor VRx: ");
  Serial.print(map(valorEixoX,0,1023,0,180));   
  Serial.print("  Valor VRy: ");
  Serial.print(map(valorEixoY,0,1023,1023,0));  

 if (statusBtn) {
     Serial.println("  Botao: [Solto] ");
 } else {
     Serial.println("  Botao: [Apertado] ");
 }  
  
}
