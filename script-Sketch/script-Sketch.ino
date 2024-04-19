#include <hcsr04.h>
#include <NewPing.h>

#define TRIG_P 4 // recebe o sinal
#define ECHO_P 3 // envia o sinal
#define MAX_DISTANCE 13

NewPing sonar(TRIG_P, ECHO_P, MAX_DISTANCE);

#define pinMot1A 5
#define pinMot1B 9
#define pinMot2A 6
#define pinMot2B 10

void setup(){
    pinMode(pinMot1A, OUTPUT);
    pinMode(pinMot1B, OUTPUT);
    pinMode(pinMot2A, OUTPUT);
    pinMode(pinMot2B, OUTPUT);

    Serial.begin(9600);
}

void loop(){

    float dist = sonar.ping_cm();

    char value;

    if(Serial.available()){
        value = Serial.read();

        Serial.write(value);

        switch (value) {

          case 's':
            Serial.println("parar");
            digitalWrite(pinMot1A, LOW);
            digitalWrite(pinMot1B, LOW);
            digitalWrite(pinMot2A, LOW);
            digitalWrite(pinMot2B, LOW);
            break;

          case 'w':
            Serial.println("pra frente");
            digitalWrite(pinMot1A, HIGH);
            digitalWrite(pinMot1B, HIGH);
            break;


          case 'a':
            digitalWrite(pinMot2A, HIGH);
            digitalWrite(pinMot1B, HIGH);
            break;

          case 'd':
            digitalWrite(pinMot1A, HIGH);
            digitalWrite(pinMot2B, HIGH);
            break;
            
          case 'S':
            digitalWrite(pinMot2A, HIGH);
            digitalWrite(pinMot2B, HIGH);
            break;

          default: 
            break;
        }

    } else if (Serial.read() == 68 || Serial.read() == '+68' || (dist > 0 && dist < 12)){
        Serial.print("Parou tudo");
        digitalWrite(pinMot1A, LOW);
        digitalWrite(pinMot1B, LOW);
    } 

}
