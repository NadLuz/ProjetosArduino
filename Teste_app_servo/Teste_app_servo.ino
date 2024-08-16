#define ledVm 3
#define ledAm 6
#define ledVd 9

int fadeAmount= 5;
int brightness = 0;
//alterar para o Servo
void setup()
{
  Serial.begin(9600);
  pinMode(ledVm, OUTPUT);
  pinMode(ledAm, OUTPUT);
  pinMode(ledVd, OUTPUT);  
}

void loop(){
  if (Serial.available()> 0)
  {
    char data = Serial.read();
    if (data == 'D') //direita
    {
      digitalWrite(ledVm, HIGH);
      digitalWrite(ledAm, LOW);
      digitalWrite(ledVd, LOW);
    }
    else if (data == 'E') //esquerda
    {
      digitalWrite(ledVm, LOW);
      digitalWrite(ledAm, HIGH);
      digitalWrite(ledVd, LOW);      
    }
    else if (data == 'G')
    {
      digitalWrite(ledVm, LOW);
      digitalWrite(ledAm, LOW);
      digitalWrite(ledVd, HIGH);      
    }
  
    else if(data =='P')
    {
     for ( int i = 0; i<300; i++)
     {
       analogWrite (ledVm, brightness);
       analogWrite (ledAm, brightness);
       analogWrite (ledVd, brightness);
      // mudar brilho
       brightness= brightness + fadeAmount;
       
       //Inverter a direção
       if(brightness <=0 || brightness >=255)
       {
         fadeAmount = -fadeAmount;
        }
  delay(30);
      }
    }
      

  } 
  
}
