#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INICIAL 0
#define Q1 1
#define Q2 2
#define $ 0
#define R 1
#define RECHAZADO 3

typedef struct nodo{
        char info;
        struct nodo * sgte;
    } elemento;

void push (elemento * , char);
char pop (elemento *);

int main (){

    elemento * pila = (elemento*) malloc (sizeof (elemento));
    pila -> info = '$';
    pila -> sgte = NULL;

    //Declaracion de la tabla de transicion:

    typedef struct proxEstado {
        int estado;
        char cimaPila;
        int parentesis;
    } proximoEstado;

    proximoEstado inicialVacio = { INICIAL, '$'};
    proximoEstado inicialLleno = { INICIAL, 'R'};
    proximoEstado parentesisVacio = { INICIAL, '$', 1};
    proximoEstado parentesisLleno = { INICIAL, 'R', 1};
    proximoEstado q1Vacio = { Q1, '$'};
    proximoEstado q1Lleno = { Q1, 'R'};
    proximoEstado cierroParentesis = {Q2};
    proximoEstado rechazado = {RECHAZADO} ;


    proximoEstado tablaDeTransicion [3] [2] [5];

    tablaDeTransicion [INICIAL] [$] [0] = rechazado;
    tablaDeTransicion [INICIAL] [$] [1] = q1Vacio;
    tablaDeTransicion [INICIAL] [$] [2] = rechazado;
    tablaDeTransicion [INICIAL] [$] [3] = parentesisVacio;
    tablaDeTransicion [INICIAL] [$] [4] = rechazado;
    tablaDeTransicion [INICIAL] [R] [0] = rechazado;
    tablaDeTransicion [INICIAL] [R] [1] = q1Lleno;
    tablaDeTransicion [INICIAL] [R] [2] = rechazado;
    tablaDeTransicion [INICIAL] [R] [3] = parentesisLleno;
    tablaDeTransicion [INICIAL] [R] [4] = rechazado;

    tablaDeTransicion [Q1] [$] [0] = q1Vacio;
    tablaDeTransicion [Q1] [$] [1] = q1Vacio;
    tablaDeTransicion [Q1] [$] [2] = inicialVacio;
    tablaDeTransicion [Q1] [$] [3] = rechazado;
    tablaDeTransicion [Q1] [$] [4] = rechazado;
    tablaDeTransicion [Q1] [R] [0] = q1Lleno;
    tablaDeTransicion [Q1] [R] [1] = q1Lleno;
    tablaDeTransicion [Q1] [R] [2] = inicialLleno;
    tablaDeTransicion [Q1] [R] [3] = rechazado;
    tablaDeTransicion [Q1] [R] [4] = cierroParentesis;

    tablaDeTransicion [Q2] [$] [0] = rechazado;
    tablaDeTransicion [Q2] [$] [1] = rechazado;
    tablaDeTransicion [Q2] [$] [2] = inicialVacio;
    tablaDeTransicion [Q2] [$] [3] = rechazado;
    tablaDeTransicion [Q2] [$] [4] = rechazado;
    tablaDeTransicion [Q2] [R] [0] = rechazado;
    tablaDeTransicion [Q2] [R] [1] = rechazado;
    tablaDeTransicion [Q2] [R] [2] = inicialLleno;
    tablaDeTransicion [Q2] [R] [3] = rechazado;
    tablaDeTransicion [Q2] [R] [4] = cierroParentesis;

//Ingreso de datos:
    printf ("Introdusca una expresión aritmetica:");
    char expresion [50];
    scanf ("%s", expresion);
    printf ("\n");

    int i = 0;
    int caracter, cimaP;
    int estadoActual = INICIAL;
    char evaluado, proxCima;
    proximoEstado bloqueActual;

// Analisis de cada caracter recibido
    while (expresion [i]) {
        evaluado = expresion [i];
        if (evaluado != ' '){                                   //analiza el caracter recibido
            if (evaluado == '0'){
                caracter = 0;
            } else if (evaluado >= '1' && evaluado <= '9'){
                caracter = 1;
            } else if (evaluado == '+' || evaluado == '-' || evaluado == '*' || evaluado == '/'){
                caracter = 2;
            } else if (evaluado == '('){
                caracter = 3;
            } else {
                caracter = 4;
            }

            if (pop (pila) == '$'){                             //analiza el estado de la pila
                cimaP = $;
            } else {
                cimaP = R;
            }

            bloqueActual = tablaDeTransicion [estadoActual] [cimaP] [caracter];  //opera a partir de los resultados

            estadoActual = bloqueActual.estado;

            if (estadoActual == RECHAZADO){
            	break;
            }

            proxCima = bloqueActual.cimaPila,

            push (pila, proxCima );


            if (bloqueActual.parentesis == 1){
                push (pila, 'R');
            }
        }

        i++;

    }
//comunica el resultado
    switch (estadoActual)
    {
    case Q1 || Q2:
    	if (pop (pila) != 'R'){
    		printf ("La expresión %s es sintacticamente correcta \n", expresion);
    	} else {
    		printf ("La expresión %s no es sintacticamente correcta \n", expresion);
    	}

        break;

    default:
        printf ("La expresión %s no es sintacticamente correcta \n", expresion);
        break;
    }


    return 0;
}

void push (elemento* pila, char x){
    elemento * nuevo = (elemento*) malloc (sizeof (elemento));
    nuevo -> info = x;
    nuevo -> sgte = pila;
    pila = nuevo;
}

char pop (elemento * pila){
    elemento * p = pila;
    char x = p -> info;
    pila = p -> sgte;
    free (p);
    return x;
}

