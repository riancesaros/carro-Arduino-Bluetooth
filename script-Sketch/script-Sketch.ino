#include <NewPing.h>

// Define os pinos para o sensor de ultrassom
#define TRIG_P 4 // Pino para enviar o sinal
#define ECHO_P 3 // Pino para receber o sinal
#define MAX_DISTANCE 13 // Distância máxima para medição

// Define os pinos para controle dos motores
#define pinMot1A 5
#define pinMot1B 9
#define pinMot2A 6
#define pinMot2B 10

// Cria um objeto 'sonar' para o sensor de ultrassom
NewPing sonar(TRIG_P, ECHO_P, MAX_DISTANCE);
char prevPreviousValue = '!';
char previousValue = '!';
char value = '!';

void setup() {
    // Configura todos os pinos dos motores como saída
    pinMode(pinMot1A, OUTPUT);
    pinMode(pinMot1B, OUTPUT);
    pinMode(pinMot2A, OUTPUT);
    pinMode(pinMot2B, OUTPUT);

    // Inicializa a comunicação serial com a taxa de 9600 bps
    Serial.begin(9600);
}

void freio(){
  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot1B, LOW);
  digitalWrite(pinMot2A, LOW);
  digitalWrite(pinMot2B, LOW);
}

void frente(){
  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot1B, HIGH);
}
void freioFrente(){
  digitalWrite(pinMot1A, LOW);
  digitalWrite(pinMot1B, LOW);
}

void esquerda(){
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot1B, HIGH);
}
void freioEsquerda(){
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot1B, HIGH);
}

void direita(){
  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot2B, HIGH);
}
void freioDireita(){
  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot2B, HIGH);
}

void re(){
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot2B, HIGH);
}
void freioRe(){
  digitalWrite(pinMot2A, LOW);
  digitalWrite(pinMot2B, LOW);
}



void loop() {
    // Realiza uma leitura da distância pelo sensor de ultrassom
    float dist = sonar.ping_cm();

    // Declara uma variável para armazenar o caractere recebido pela comunicação serial

    // Verifica se há dados disponíveis na porta serial
    if (Serial.available()) {
        // Lê o caractere disponível na porta serial
        prevPreviousValue = previousValue;
        previousValue = value;
        value = Serial.read();

        Serial.print(value);

        // Executa uma ação de acordo com o caractere recebido
        if((value == 'w' || (previousValue == 'w' && value != 'W')) || (prevPreviousValue == 'w' && previousValue != 'W' && value != 'W')){
          frente();
        } else if (value == 'W' || (prevPreviousValue == 'w' && previousValue == 'W')){
          freioFrente();
        }

        if((value == 's' || (previousValue == 's' && value != 'S')) || (prevPreviousValue == 's' && previousValue != 'S' && value != 'S')){
          re();
        } else if (value == 'S' || (prevPreviousValue == 's' && previousValue == 'S')) {
          freioRe();
        }

        if((value == 'a' || (previousValue == 'a' && value != 'A')) || (prevPreviousValue == 'a' && previousValue != 'A' && value != 'A')){
          esquerda();
        } else if (value == 'A' || (prevPreviousValue == 'a' && previousValue == 'A')) {
          freioEsquerda();
        }
        
        if((value == 'd' || (previousValue == 'd' && value != 'D')) || (prevPreviousValue == 'd' && previousValue != 'D' && value != 'D')){
          direita();
        } else if (value == 'D' || (prevPreviousValue == 'd' && previousValue == 'D')){
          freioDireita();
        }


    } else if (Serial.read() == 68 || Serial.read() == '+68' || (dist > 0 && dist < 12)) {
        // Se não houver dados disponíveis na porta serial ou a leitura do sensor estiver entre 0 e 12 cm
        digitalWrite(pinMot1A, LOW);
        digitalWrite(pinMot1B, LOW);
    } 

 
}