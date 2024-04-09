/*
#define pinMot1A 5
#define pinMot1B 9
#define pinMot2A 6
#define pinMot2B 10

void setup() {
  // put your setup code here, to run once:
  pinMode(pinMot1A, OUTPUT);
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinMot2A, OUTPUT);
  pinMode(pinMot2B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinMot1A, HIGH);
  delay(2000);
  digitalWrite(pinMot1A, LOW);

  digitalWrite(pinMot2A, HIGH);
  delay(2000);
  digitalWrite(pinMot2A, LOW);

  digitalWrite(pinMot1B, HIGH);
  delay(2000);
  digitalWrite(pinMot1B, LOW);

  digitalWrite(pinMot2B, HIGH);
  delay(2000);
  digitalWrite(pinMot2B, LOW);

  
}
*/
#define pinMot1A 5 
#define pinMot1B 9
#define pinMot2A 6
#define pinMot2B 10

void setup() {
  // put your setup code here, to run once:
  pinMode(pinMot1A, OUTPUT);
  pinMode(pinMot1B, OUTPUT);
  pinMode(pinMot2A, OUTPUT);
  pinMode(pinMot2B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot2A, HIGH);
  delay(1000);
  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot2A, LOW);

  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot2B, HIGH);
  delay(2000);
  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot2B, LOW);

  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot1B, HIGH);
  delay(2000);
  digitalWrite(pinMot2A, LOW);
  digitalWrite(pinMot1B, LOW);

  
}
