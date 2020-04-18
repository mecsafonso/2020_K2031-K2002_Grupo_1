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

void estadoFinal (int, FILE*); //Detecta en que estado se escuentra el automata y graba un mensaje en el archivo de salida dependiendo del mismo

int columnaSgt (char); //Analiza a que columna de la matriz automata debe acceder

int main (){


    FILE * original = fopen ("entrada.txt", "r");
    FILE * arcFinal = fopen ("salida.txt", "w");
    int estadoActual = INICIO;
    char simbolo;    

    //Matriz del Automata

    int automata [6] [8];
    automata [INICIO] [0] = Q2;
    automata [INICIO] [1] = Q1;
    automata [INICIO] [2] = Q1;
    automata [INICIO] [3] = RECHAZO;
    automata [INICIO] [4] = RECHAZO;
    automata [INICIO] [5] = RECHAZO;
    automata [INICIO] [6] = RECHAZO;
    automata [INICIO] [7] = RECHAZO;

    automata [Q1] [0] = Q1;
    automata [Q1] [1] = Q1;
    automata [Q1] [2] = Q1;
    automata [Q1] [3] = RECHAZO;
    automata [Q1] [4] = RECHAZO;
    automata [Q1] [5] = RECHAZO;
    automata [Q1] [6] = RECHAZO;
    automata [Q1] [7] = RECHAZO;

    automata [Q2] [0] = Q5;
    automata [Q2] [1] = Q5;
    automata [Q2] [2] = RECHAZO;
    automata [Q2] [3] = Q3;
    automata [Q2] [4] = Q3;
    automata [Q2] [5] = RECHAZO;
    automata [Q2] [6] = RECHAZO;
    automata [Q2] [7] = RECHAZO;

    automata [Q3] [0] = Q4;
    automata [Q3] [1] = Q4;
    automata [Q3] [2] = Q4;
    automata [Q3] [3] = RECHAZO;
    automata [Q3] [4] = RECHAZO;
    automata [Q3] [5] = Q4;
    automata [Q3] [6] = Q4;
    automata [Q3] [7] = RECHAZO;

    automata [Q4] [0] = Q4;
    automata [Q4] [1] = Q4;
    automata [Q4] [2] = Q4;
    automata [Q4] [3] = RECHAZO;
    automata [Q4] [4] = RECHAZO;
    automata [Q4] [5] = Q4;
    automata [Q4] [6] = Q4;
    automata [Q4] [7] = RECHAZO;

    automata [Q5] [0] = Q5;
    automata [Q5] [1] = Q5;
    automata [Q5] [2] = RECHAZO;
    automata [Q5] [3] = RECHAZO;
    automata [Q5] [4] = RECHAZO;
    automata [Q5] [5] = RECHAZO;
    automata [Q5] [6] = RECHAZO;
    automata [Q5] [7] = RECHAZO;
   

    while ((simbolo = fgetc(original)) != EOF){

        if (simbolo == ','){
            estadoFinal (estadoActual, arcFinal);
            estadoActual = INICIO;
        }

        else {
            if(estadoActual != RECHAZO) {                
            estadoActual = automata [estadoActual] [columnaSgt (simbolo)];
            }
            fprintf (arcFinal, "%c", simbolo);
        }
    }

    estadoFinal (estadoActual, arcFinal);

    fclose (arcFinal);
    fclose (original);


    return 0;
}

void estadoFinal (int estadoActual, FILE* arcFinal){
    switch (estadoActual){
        case INICIO:
            fprintf (arcFinal, "\t Espacio en blanco.\n");
            break;
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
            fprintf (arcFinal, "\t no reconocido.\n");
            break;
    }
}

int columnaSgt (char simbolo){
    int j = 0;
    char limiteInf [] = "018xXaA";
    char limiteSup [] = "079xXfF";
    while (limiteInf [j] != NULL){
        if (limiteInf [j] <= simbolo && simbolo <= limiteSup [j]){
            return j;
        }
        j++;
    }
    return j;
}