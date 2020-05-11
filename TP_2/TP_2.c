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

typedef struct pila{
	elemento* inicio;
} Pila;

elemento* crearNodo (char);
void destruirNodo (elemento*);
void push (Pila * , char);
char pop (Pila *);
void imprimirMensaje (char, char [50], char, char, int, int);

int main (){

    Pila* pila = (Pila*)malloc (sizeof (Pila*));
    push (pila, '$');

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
    proximoEstado cierroParentesis = {Q2,'$',2};
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


    printf ("Introdusca una expresión aritmetica (maximo de 50 caracteres): \n");
    char expresion [50];
    gets (expresion);

    int i = 0;
    int caracter, cimaP;
    int estadoActual = INICIAL;
    char evaluado, proxCima, error;
    proximoEstado bloqueActual;

    while (expresion [i]) {
        evaluado = expresion [i];

        if (evaluado != ' '){
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

            proxCima = pop (pila);

            if (proxCima == '$'){
                cimaP = $;
            } else {
                cimaP = R;
            }

            bloqueActual = tablaDeTransicion [estadoActual] [cimaP] [caracter];

            estadoActual = bloqueActual.estado;

            if (estadoActual == RECHAZADO){

            	error = evaluado;
            	break;
            }

            proxCima = bloqueActual.cimaPila;

            if (bloqueActual.parentesis !=2){
            	push (pila, proxCima );
            	if (bloqueActual.parentesis == 1){
            		push (pila, 'R');
            	}
            }

        }

        i++;

    }

    proxCima = pop (pila);
    imprimirMensaje (proxCima, expresion, evaluado, error, i, estadoActual);


    return 0;
}

void imprimirMensaje (char proxCima, char expresion [50], char evaluado, char error, int posicion, int estadoActual){
	if ((estadoActual == Q1 || estadoActual == Q2) && proxCima == '$'){
	    printf ("La expresión %s es sintacticamente correcta \n", expresion);
    } else {
    	printf ("La expresión %s no es sintacticamente correcta \n", expresion);
    	if (error == evaluado){
    		printf ("Es posible que falte un caracter previo al que se encuentra en la posición %d: %c",(posicion+1), error);
    	} else if (proxCima == 'R'){
    		printf ("Se encontraron parentesis abiertos que no fueron cerrados");
    	} else {
    		printf ("El error se encuentra en que %c no puede ser el ultimo elemento de la expresion", evaluado);
    	}
    }
}

void push (Pila* pila, char x){
    elemento * nuevo = crearNodo (x);
    nuevo -> sgte = pila ->inicio;
    pila ->inicio = nuevo;
}

char pop (Pila * pila){
    elemento * p = pila->inicio;
    pila -> inicio = p -> sgte;
    char x = p -> info;
    destruirNodo (p);
    return x;
}

elemento* crearNodo (char x){
	elemento* nodo = (elemento*)malloc (sizeof (elemento));
	nodo ->info = x;
	nodo ->sgte = NULL;
	return nodo;
}

void destruirNodo (elemento* nodo){
	nodo->sgte = NULL;
	free (nodo);
}
