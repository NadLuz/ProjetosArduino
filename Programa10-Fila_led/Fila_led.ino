int pinLed [6] = {2,3,4,5,6,7};
int Led;
char Pausa;
void setup(){
  int x;
  for(x=0; x<=5; x++){
    pinMode (pinLed[x], OUTPUT);
  }
  Serial.begin(9600);
}
void loop(){
  
}