#include <SoftwareSerial.h> // permite o uso do hc-06 em qualquer porta
#include <hcsr04.h>

// direções possivel (como o bluetooth so retorna um char, associei os valores a nomes para ficar mais facil de ler)
#define right 'a'
#define left 'd' 
#define down 's'
#define up 'w' 

#define pinMot1A 5 
#define pinMot1B 6
#define pinMot2A 9
#define pinMot2B 10

// portas do sensor
#define TRIG_P 2 // recebe o sinal
#define ECHO_P 13 // envia o sinal

SoftwareSerial bt_serial(11, 12); // RX e TX
HCSR04 hcsr04(TRIG_P, ECHO_P, 20, 4000); // cria o objeto do sensor hcsr04 ( nao implementado ao codigo )

int gates[4] = {3, 4, 7, 8}; // portas a serem controladas pelo bluetooth
int motores[4] = {5, 6, 9, 10}; // motores

void setup(){

    // output pinMode
    for(int i = 0; i < 4; i++){
        pinMode(gates[i], OUTPUT);
        pinMode(motores[i], OUTPUT);
    }

    // input pinMode
    // for(int i = 0; i < 3; i++){
    //     pinMode(gates[i], INPUT);
    // }

    bt_serial.begin(9600); 
}

void virarEsquerda(){
    digitalWrite(motores[/* motores da direita */ 0], HIGH);
}
void acelerar(){
    for(int i = 0; i < 4; i++){
        digitalWrite(motores[i], HIGH); /* todos os motores */ 
    }
}
void virarDireita(){
    digitalWrite(motores[/* motores da esquerda */ 0], HIGH);
}
void re(){
    digitalWrite(motores[/* como q faz o motor girar pra tras????????? */ 0], HIGH);
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


