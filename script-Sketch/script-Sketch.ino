// #include <SoftwareSerial.h> // permite o uso do hc-06 em qualquer porta
#include <hcsr04.h>

// // direções possivel (como o bluetooth so retorna um char, associei os valores a nomes para ficar mais facil de ler)
// #define right 'a'
// #define left 'd' 
// #define down 's' 
// #define up 'w' 

// // portas do sensor
#define TRIG_P 4 // recebe o sinal
#define ECHO_P 3 // envia o sinal

// SoftwareSerial bt_serial(11, 12); // RX e TX
HCSR04 hcsr04(TRIG_P, ECHO_P, 20, 4000); // cria o objeto do sensor hcsr04 ( nao implementado ao codigo )

// int gates[4] = {3, 4, 7, 8}; // portas a serem controladas pelo bluetooth
// int motores[4] = {5, 6, 9, 10}; // motores

// void setup(){

//     // output pinMode
//     for(int i = 0; i < 4; i++){
//         pinMode(gates[i], OUTPUT);
//         pinMode(motores[i], OUTPUT);
//     }

//     // input pinMode
//     // for(int i = 0; i < 3; i++){
//     //     pinMode(gates[i], INPUT);
//     // }

//     bt_serial.begin(9600); 
// }

// void virarEsquerda(){
//     digitalWrite(motores[/* motores da direita */ 0], HIGH);
// }
// void acelerar(){
//     for(int i = 0; i < 4; i++){
//         digitalWrite(motores[i], HIGH); /* todos os motores */ 
//     }
// }
// void virarDireita(){
//     digitalWrite(motores[/* motores da esquerda */ 0], HIGH);
// }
// void re(){
//     digitalWrite(motores[/* como q faz o motor girar pra tras????????? */ 0], HIGH);
// }

// void loop(){
    
//     if(bt_serial.read()){ // Se a porta serial estiver recebendo um valor
//         char value = bt_serial.read(); // recebe a entrada de valor do bluetooth
       
//         do {
//             switch (value)
//             {
//             case up:
//                 acelerar();
//                 break;
            
//             case down:
//                 re();
//                 break;

//             case left:
//                 virarEsquerda();
//                 break;

//             case right: 
//                 virarDireita();
//                 break;
                
//             default: // caso esteja tudo configurado, nem vai cair no default
//                 break;
//             } 
//         } while (value);
//     };
// }

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

    float dist;
    dist = hcsr04.distanceInMillimeters();


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

    } else if (Serial.read() == 68 || Serial.read() == "+68" || dist < 80){
        Serial.print("Parou tudo");
        digitalWrite(pinMot1A, LOW);
        digitalWrite(pinMot1B, LOW);
        digitalWrite(pinMot2A, LOW);
        digitalWrite(pinMot2B, LOW);

    } 

    Serial.println(dist);
}
