long Ultrasonic (int triggerPin, int echoPin){
  pinMode (triggerPin, OUTPUT);
  digitalWrite (triggerPin, LOW);
  delayMicroseconds (2);
  digitalWrite (triggerPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn (echoPin, HIGH);
}

void setup (){
  Serial.begin(9600);
  pinMode (10, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (8, OUTPUT);
}

void loop(){
  Serial.println (0.01723*Ultrasonic (5,4));
  if (0.01723*Ultrasonic (5,4) <10) {
    digitalWrite (10, HIGH);
    digitalWrite (9, LOW);
    digitalWrite (8, LOW);
  }
  else{
    if (0.01723 * Ultrasonic(5,4) <20){
      digitalWrite (10, LOW);
      digitalWrite (9, HIGH);
      digitalWrite (8, LOW);
    }
    else {
      digitalWrite (10, LOW);
      digitalWrite (9, LOW);
      digitalWrite (8, HIGH);
    }
  }
  delay (10);
}