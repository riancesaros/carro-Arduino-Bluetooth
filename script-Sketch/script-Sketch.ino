#include <NewPing.h>

// Define os pinos para o sensor de ultrassom
#define TRIG_P 4 // Pino para enviar o sinal
#define ECHO_P 3 // Pino para receber o sinal
#define MAX_DISTANCE 14 // Distância máxima para medição

// Cria um objeto 'sonar' para o sensor de ultrassom
NewPing sonar(TRIG_P, ECHO_P, MAX_DISTANCE);

// Define os pinos para controle dos motores
#define pinMot1A 5
#define pinMot1B 9
#define pinMot2A 6
#define pinMot2B 10

int vel = 255;

void setup() {
    // Configura todos os pinos dos motores como saída
    pinMode(pinMot1A, OUTPUT);
    pinMode(pinMot1B, OUTPUT);
    pinMode(pinMot2A, OUTPUT);
    pinMode(pinMot2B, OUTPUT);

    // Inicializa a comunicação serial com a taxa de 9600 bps
    Serial.begin(9600);
}

void loop() {
  //  digitalWrite(pinMot2A, vel); frente esquerda
  //  digitalWrite(pinMot1B, vel); frente direita

    // Declara uma variável para armazenar o caractere recebido pela comunicação serial
    char value;

    // Verifica se há dados disponíveis na porta serial
    if (Serial.available()) {
        // Lê o caractere disponível na porta serial
        value = Serial.read();
        // Envia de volta o caractere lido
        Serial.write(value);
        Serial.println(" ");

        if(
          value == '0'||
          value == '1'||
          value == '2'||
          value == '3'||
          value == '4'||
          value == '5'||
          value == '6'||
          value == '7'||
          value == '8'||
          value == '9'||
          (value == 'q')
        )
        
        {
          if(value == 'q'){
            value = 10;
            vel = value * 25.5;
          } else {
            int index = int(value) - 48;
            vel = index * 25.5;
          }
        }
        

        // Executa uma ação de acordo com o caractere recebido
        switch (value) {
            case 'S': // Se receber 's', para os motores
                Serial.println(vel);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot1B, LOW);
                analogWrite(pinMot2A, LOW);
                analogWrite(pinMot2B, LOW);
                break;

            case 'F': // Se receber 'w', movimenta para frente
                Serial.println(vel);
                analogWrite(pinMot2B, LOW);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot2A, vel);
                analogWrite(pinMot1B, vel);
                break;

            case 'L': // Se receber 'a', movimenta para a esquerda
                Serial.println(vel);
                analogWrite(pinMot2B, LOW);
                analogWrite(pinMot2A, LOW);
                analogWrite(pinMot1A, vel);
                analogWrite(pinMot1B, vel);
                break;

            case 'R': // Se receber 'd', movimenta para a direita
                Serial.println(vel);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot2A, vel);
                analogWrite(pinMot2B, vel);
                break;

            case 'B': // Se receber 'S', movimenta para trás
                Serial.println(vel);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot2A, LOW);
                analogWrite(pinMot1A, vel);
                analogWrite(pinMot2B, vel);
                break;
            case 'G':
                Serial.println(vel);
                analogWrite(pinMot1B, vel);
                analogWrite(pinMot2A, LOW);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot2B, LOW);
                break;
            case 'I':
                Serial.println(vel);
                analogWrite(pinMot2A, vel);
                analogWrite(pinMot1B, LOW);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot2B, LOW);
                break;
            case 'H':
                Serial.println(vel);
                analogWrite(pinMot1A, vel);
                analogWrite(pinMot1B, LOW);
                analogWrite(pinMot2A, LOW);
                analogWrite(pinMot2B, LOW);
                break;
            case 'J':
                Serial.println(vel);
                analogWrite(pinMot2B, vel);
                analogWrite(pinMot1B, LOW);
                analogWrite(pinMot1A, LOW);
                analogWrite(pinMot2A, LOW);
                break;
            default: 
                break;
        }
    } 
}
