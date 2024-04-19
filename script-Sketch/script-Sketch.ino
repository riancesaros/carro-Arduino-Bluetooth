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

void esquerda(){
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot1B, HIGH);
}

void direita(){
  digitalWrite(pinMot1A, HIGH);
  digitalWrite(pinMot2B, HIGH);
}

void re(){
  digitalWrite(pinMot2A, HIGH);
  digitalWrite(pinMot2B, HIGH);
}



void loop() {
    // Realiza uma leitura da distância pelo sensor de ultrassom
    float dist = sonar.ping_cm();

    // Declara uma variável para armazenar o caractere recebido pela comunicação serial
    char value;

    // Verifica se há dados disponíveis na porta serial
    if (Serial.available()) {
        // Lê o caractere disponível na porta serial
        value = Serial.read();

        Serial.print(value);

        // Executa uma ação de acordo com o caractere recebido
        switch (value) {
            case 's': // Se receber 's', para os motores
              freio();
              break;

            case 'w': // Se receber 'w', movimenta para frente
              frente();
              break;

            case 'a': // Se receber 'a', movimenta para a esquerda
              esquerda();
              break;

            case 'd': // Se receber 'd', movimenta para a direita
              direita();
              break;

            case 'S': // Se receber 'S', movimenta para trás
              re();
              break;

            default: 
                break;
        }
    } else if (Serial.read() == 68 || Serial.read() == '+68' || (dist > 0 && dist < 12)) {
        // Se não houver dados disponíveis na porta serial ou a leitura do sensor estiver entre 0 e 12 cm
        digitalWrite(pinMot1A, LOW);
        digitalWrite(pinMot1B, LOW);
    } 

    if(value == 'wa' || value == 'aw'){
      Serial.println('retoEsquerda');
    }
}