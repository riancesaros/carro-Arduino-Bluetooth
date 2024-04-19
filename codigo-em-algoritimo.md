Incluir bibliotecas "hcsr04.h" e "NewPing.h"

Constante TRIG_P = 4 // Pino para enviar o sinal
Constante ECHO_P = 3 // Pino para receber o sinal
Constante MAX_DISTANCE = 13 // Distância máxima para medição

Criar um objeto 'sonar' para o sensor de ultrassom usando TRIG_P, ECHO_P e MAX_DISTANCE

Constantes pinMot1A = 5, pinMot1B = 9, pinMot2A = 6, pinMot2B = 10 // Define os pinos para controle dos motores

Função setup():
    Configurar todos os pinos dos motores como saída
    Inicializar a comunicação serial com a taxa de 9600 bps

Função loop():
    Ler a distância pelo sensor de ultrassom e armazenar em 'dist'

    Se houver dados disponíveis na porta serial:
        Ler o caractere disponível na porta serial e armazenar em 'value'
        Enviar de volta o caractere lido

        Caso 'value' seja 's':
            Parar os motores
        Caso 'value' seja 'w':
            Movimentar para frente
        Caso 'value' seja 'a':
            Movimentar para a esquerda
        Caso 'value' seja 'd':
            Movimentar para a direita
        Caso 'value' seja 'S':
            Movimentar para trás

    Senão, se a leitura do sensor estiver entre 0 e 12 cm:
        Parar os motores