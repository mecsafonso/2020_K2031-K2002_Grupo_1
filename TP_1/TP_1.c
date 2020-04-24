#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Estados del Automata*/
#define INICIO  0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4
#define Q5 5
#define RECHAZO 6

//Variables Cosntantes
const char CENTINELA = ',';

//FUNCIOINES
void ejecutarAutomata (FILE*, FILE*);   //Ejecuta el automata y genera un txt de salida
void estadoFinal (int, FILE*);          //Detecta en que estado se escuentra el automata y graba un mensaje en el archivo de salida dependiendo del mismo
int columnaSgt (char);                  //Analiza a que columna de la matriz automata debe acceder


int main (){
    //Apertura del archivo para lectura y el archivo de salida
    FILE * original = fopen ("entrada.txt", "r");
    FILE * arcFinal = fopen ("salida.txt", "w");

    ejecutarAutomata (original, arcFinal);

    //Cierre del archivo para lectura y el archivo de salida
    fclose (arcFinal);
    fclose (original);

    return 0;
}

void ejecutarAutomata (FILE* original, FILE* arcFinal){
    int estadoActual = INICIO;
    char caracter;    

    //Matriz del Automata

    int automata [7] [6];
    automata [INICIO] [0] = Q2;
    automata [INICIO] [1] = Q1;
    automata [INICIO] [2] = Q1;
    automata [INICIO] [3] = RECHAZO;
    automata [INICIO] [4] = RECHAZO;
    automata [INICIO] [5] = RECHAZO;

    automata [Q1] [0] = Q1;
    automata [Q1] [1] = Q1;
    automata [Q1] [2] = Q1;
    automata [Q1] [3] = RECHAZO;
    automata [Q1] [4] = RECHAZO;
    automata [Q1] [5] = RECHAZO;

    automata [Q2] [0] = Q5;
    automata [Q2] [1] = Q5;
    automata [Q2] [2] = RECHAZO;
    automata [Q2] [3] = Q3;
    automata [Q2] [4] = RECHAZO;
    automata [Q2] [5] = RECHAZO;

    automata [Q3] [0] = Q4;
    automata [Q3] [1] = Q4;
    automata [Q3] [2] = Q4;
    automata [Q3] [3] = RECHAZO;
    automata [Q3] [4] = Q4;
    automata [Q3] [5] = RECHAZO;

    automata [Q4] [0] = Q4;
    automata [Q4] [1] = Q4;
    automata [Q4] [2] = Q4;
    automata [Q4] [3] = RECHAZO;
    automata [Q4] [4] = Q4;
    automata [Q4] [5] = RECHAZO;

    automata [Q5] [0] = Q5;
    automata [Q5] [1] = Q5;
    automata [Q5] [2] = RECHAZO;
    automata [Q5] [3] = RECHAZO;
    automata [Q5] [4] = RECHAZO;
    automata [Q5] [5] = RECHAZO; 

    automata [RECHAZO] [0] = RECHAZO;
    automata [RECHAZO] [1] = RECHAZO;
    automata [RECHAZO] [2] = RECHAZO;
    automata [RECHAZO] [3] = RECHAZO;
    automata [RECHAZO] [4] = RECHAZO;
    automata [RECHAZO] [5] = RECHAZO;  

    //Se evalúa cada palabra caracter a carater para definir un estadoFinal -> decimal, octal, hexadecimal o NO reconocido
    while ((caracter = fgetc(original)) != EOF){

        if (caracter == CENTINELA){
            estadoFinal (estadoActual, arcFinal);
            estadoActual = INICIO;
        }
        else {               
            estadoActual = automata [estadoActual] [columnaSgt (caracter)];
            fprintf (arcFinal, "%c", caracter);
        }
    }
    estadoFinal (estadoActual, arcFinal);
}

void estadoFinal (int estadoActual, FILE* arcFinal){
    switch (estadoActual){
        case Q1:
            fprintf (arcFinal, "\t es un decimal.\n");
            break;
        case Q4:
            fprintf (arcFinal, "\t es un hexadecimal.\n");
            break;
        case Q5:
            fprintf (arcFinal, "\t es un octal.\n");
            break;
        default:
            fprintf (arcFinal, "\t NO reconocido.\n");
            break;
    }
}

int columnaSgt (char caracter){   
    if (caracter == '0') {
        return INICIO;
    }
        else if  (caracter >= '1' && caracter <= '7'){
            return Q1;
        }
        else if  (caracter == '8' || caracter == '9'){
            return Q2;
        }    
        else if  (caracter == 'x' || caracter == 'X'){
            return Q3;
        }   
        else if  (caracter >= 'a' && caracter <= 'f'){
            return Q4;
        }   
        else if  (caracter >= 'A' && caracter <= 'F'){
            return Q4;
        }    
        else {
            return Q5;
        }
}