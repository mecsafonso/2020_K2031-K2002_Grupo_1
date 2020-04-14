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

int main (){

    FILE* original = fopen ("entrada.txt", "r");
    FILE* arcFinal = fopen ("salida.txt", "w");
    int estadoActual = INICIO;
    int j = 0, s;
    char comparacionNum, simbolo;

    
    /*AUTOMATA:
    Paso 1. Matriz*/

    char numeros [6];
    numeros [0] = '0';
    numeros [1] = "1234567";
    numeros [2] = "89";
    numeros [3] = "xX";
    numeros [4] = "abcdefABCDEF";

    int automata [7] [7];
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

    while ((simbolo = fgetc (original)) != EOF){
        if (simbolo == ','){
            switch (estadoActual){
                case RECHAZO:
                    fprintf (arcFinal, " no es un numero.\n");
                    break;
                case Q1:
                    fprintf (arcFinal, " es un decimal. \n");
                    break;
                case Q4:
                    fprintf (arcFinal, " es un hexadecimal.\n");
                    break;
                case Q5:
                    fprintf (arcFinal, " es un octal.\n");
                    break;
            }
        }

        else if (j < 6 && s >= 0 ){
            s = 0;
            strcmp (comparacionNum, numeros [j]);
            while (comparacionNum [s] != "\0"){
                if (simbolo == comparacionNum [s]){
                    s = -1;
                    break;
                }
                else {
                    s++;
                }
            }
            j++;                     
        }

        j= j-1;

        estadoActual = automata [estadoActual] [j];
        fprintf (arcFinal, "%c", simbolo);
    }


    return 0;



}