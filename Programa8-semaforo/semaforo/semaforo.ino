void setup() {
  pinMode (12, OUTPUT); //led vermelho
  pinMode (11,OUTPUT); //led amarelo
  pinMode (10, OUTPUT); //led verde
  pinMode (7,OUTPUT); //led vermelho
  pinMode (6, OUTPUT); //led verde
}

void loop() {
  int t1 = 2000;
  digitalWrite (10, HIGH); //verde carro
  digitalWrite (7, HIGH); //vermelho pedestre
  delay(t1); //temporizador
  digitalWrite (10, LOW); //verde carro
  digitalWrite (11, HIGH); //amarelo carro
  delay(t1);
  digitalWrite (11, LOW);//amarelo carro
  digitalWrite (12, HIGH);//vermelho carro  
  digitalWrite (7, LOW); //vermelho pedestre
  digitalWrite (6, HIGH); //verde pedestre
  delay(250);
  digitalWrite (6, LOW);//verde pedestre
  digitalWrite (6, HIGH); //verde pedestre
  delay(250);
  digitalWrite (6, LOW);//verde pedestre
  digitalWrite (6, HIGH); //verde pedestre
  delay(250);
  digitalWrite (6, LOW);//verde pedestre
  digitalWrite (7, HIGH);
  digitalWrite (12, LOW);//vermelho carro
 
  //digitalWrite (12, LOW);
}

