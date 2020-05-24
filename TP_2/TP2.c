#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>      // para usar la funcion isspace


// PREPROCESADO -----------------------
#define Q0 0
#define Q1 1
#define Q2 2
#define RECHAZO 3

// Definicion de ESTRUCTURAS -----------
struct elemento{
    char info;
    struct elemento* sgte;
};

struct proxEST {
    int estado;
    char caracter_Push;
};

typedef struct elemento Nodo;
typedef struct proxEST proximoEstado;

//Definicion de CONSTANTES -------------
const int $ = 0, R = 1;

//Definicion de VAR GLOBALES ------------
Nodo* pila = NULL;						
char cimaPila, charEvaluado, expresion[50];
int columnaCaracter, estadoActual, posicion;


// PROTOTIPO de Funciones -------------
void ejecutarAutomata ();
void suprimirEspacios(char*);
void push (char);
void imprimirPila (void);
void mensaje (int);
void submensaje (int);
void reset ();
void clearBuffer();
int menu ();
int determinarColumna (char);
char pop ();


// MAIN ---------------------------------
int main(){
    
    return menu ();
}


//DESARROLLO de funciones ----------------
int menu() {
  	char c;

  	do {
		printf("\n~~ MENU: Expresion ~~");
		printf("\n 1. Ingresar Expresion");
		printf("\n q: salir.\n");
		c = getchar();
		
		if (c == '1') {
			clearBuffer();
			ejecutarAutomata();
            reset ();			
		}
		else {
			clearBuffer();
			printf ("\n Opcion ingresada no es valida \n");
		}
  	} while(c != 'q' && c != EOF);
}


void ejecutarAutomata (){
    int cimaEnTabla;
    proximoEstado estadoSgte;

	posicion = 0;
  	estadoActual = Q0;
	

    printf("\n Introduzca una expresion aritmetica (maximo de 50 caracteres): \n");
    gets (expresion);
    suprimirEspacios (expresion);
    printf ("\n La expresion es: %s \n", expresion); 

    push ('$');			// Pongo primer valor en PILA PESO  

    //Declaracion de la tabla de transicion: ---------------
    proximoEstado Q0Vacio = { Q0, '$'};
    proximoEstado Q0Lleno = { Q0, 'R'};
    proximoEstado Q1Vacio = { Q1, '$'};
    proximoEstado Q1Lleno = { Q1, 'R'};
    proximoEstado Q2Parentesis = {Q2};
    proximoEstado rechazado = {RECHAZO} ;

    proximoEstado tablaDeTransicion [4] [2] [6];

	tablaDeTransicion [Q0] [$] [0] = rechazado;
    tablaDeTransicion [Q0] [$] [1] = Q1Vacio;
    tablaDeTransicion [Q0] [$] [2] = rechazado;
    tablaDeTransicion [Q0] [$] [3] = Q0Lleno;
    tablaDeTransicion [Q0] [$] [4] = rechazado;
	tablaDeTransicion [Q0] [$] [5] = rechazado;
    tablaDeTransicion [Q0] [R] [0] = rechazado;
    tablaDeTransicion [Q0] [R] [1] = Q1Lleno;
    tablaDeTransicion [Q0] [R] [2] = rechazado;
    tablaDeTransicion [Q0] [R] [3] = Q0Lleno;
    tablaDeTransicion [Q0] [R] [4] = rechazado;
	tablaDeTransicion [Q0] [R] [5] = rechazado;

    tablaDeTransicion [Q1] [$] [0] = Q1Vacio;
    tablaDeTransicion [Q1] [$] [1] = Q1Vacio;
    tablaDeTransicion [Q1] [$] [2] = Q0Vacio;
    tablaDeTransicion [Q1] [$] [3] = rechazado;
    tablaDeTransicion [Q1] [$] [4] = rechazado;
	tablaDeTransicion [Q1] [$] [5] = rechazado;
    tablaDeTransicion [Q1] [R] [0] = Q1Lleno;
    tablaDeTransicion [Q1] [R] [1] = Q1Lleno;
    tablaDeTransicion [Q1] [R] [2] = Q0Lleno;
    tablaDeTransicion [Q1] [R] [3] = rechazado;
    tablaDeTransicion [Q1] [R] [4] = Q2Parentesis;
	tablaDeTransicion [Q1] [R] [5] = rechazado;

    tablaDeTransicion [Q2] [$] [0] = rechazado;
    tablaDeTransicion [Q2] [$] [1] = rechazado;
    tablaDeTransicion [Q2] [$] [2] = Q0Vacio;
    tablaDeTransicion [Q2] [$] [3] = rechazado;
    tablaDeTransicion [Q2] [$] [4] = rechazado;
	tablaDeTransicion [Q2] [$] [5] = rechazado;
    tablaDeTransicion [Q2] [R] [0] = rechazado;
    tablaDeTransicion [Q2] [R] [1] = rechazado;
    tablaDeTransicion [Q2] [R] [2] = Q0Lleno;
    tablaDeTransicion [Q2] [R] [3] = rechazado;
    tablaDeTransicion [Q2] [R] [4] = Q2Parentesis;
	tablaDeTransicion [Q2] [R] [5] = rechazado;  
    
    
    // Proceso de consulta al automata caracter a caracter
	do {
		charEvaluado = expresion [posicion];				//caracter a evaluar
		columnaCaracter = determinarColumna (charEvaluado); //columna a consultar en el automata
		cimaPila = pop ();                  			    //Se saca la cima de la PILA

		if (cimaPila == '$')
			cimaEnTabla = $;
		else
			cimaEnTabla = R;

        estadoSgte = tablaDeTransicion [estadoActual] [cimaEnTabla] [columnaCaracter];    //se busca el estado sgte en la tabla de transicion 
		   
		if (estadoSgte.estado == RECHAZO)                   //Para el ciclo y deja de evaluar la expresion
			break;
		 
		else {           		
			if (estadoSgte.estado == Q2){
				if (cimaPila == '$'){		                //se mira el SGTE de la cima de PILA
				    estadoSgte.caracter_Push = cimaPila;
                }
				else {
				    estadoSgte.caracter_Push = pop (); 
                }
			} 

			estadoActual = estadoSgte.estado;

            switch (estadoActual) {		                    //Evalúo PUSH a la PILA
                case Q0: {
                    if (columnaCaracter == 3){
                        push (cimaPila);
                        push (estadoSgte.caracter_Push);
                    }
                    else
                        push (estadoSgte.caracter_Push);
                    }
                    break;                   
                default:
                    push (estadoSgte.caracter_Push);
                    break;
                }
		}
		posicion++;
        
	} while (expresion [posicion] != '\0') ;

    //Imprimir MENSAJE de salida

	if ((estadoActual == Q1 || estadoActual == Q2) && estadoSgte.caracter_Push == '$'){
	    printf ("\n Es sintacticamente correcta \n");
    }
    else {
        printf ("\n No es sintacticamente correcta");

        if (expresion [posicion] != '\0')   
            mensaje (columnaCaracter);
        else 
            submensaje (4);
    }
   reset();
}


void suprimirEspacios(char* cadena){
    int i, j;
   
    for (i = j = 0; cadena[i] != '\0'; i++)
        if (!isspace(cadena[i]))
            cadena[j++] = cadena[i];
    cadena[j] = '\0';
}


void push (char x){
    Nodo *nuevoNodo = (struct elemento*) malloc (sizeof(struct elemento));	//Asignacion de memoria dinamica -> en tiempo de ejecución

    if (NULL == nuevoNodo){
        printf("\n Error en creacion de nodo \n");
    }
    nuevoNodo -> info = x;
    nuevoNodo -> sgte = pila;
    pila = nuevoNodo;
}


char pop () {
	Nodo *aux = pila;
	char x ;
	
	x = aux -> info;   		// paso el caracter de la pila a una variable
	pila = aux -> sgte;
	free (aux);             // destruyo el nodo
    return x; 
}


void imprimirPila (void){
	if(NULL == pila){
	printf("\n La pila esta vacia \n");
	}
    else{
        Nodo *nodo = pila;

        while (nodo != NULL) {
            nodo = nodo->sgte;
	    }
	}
}

int determinarColumna (char charEvaluado){
	int columna ;
    switch (charEvaluado) {
        case '0':
            columna = 0;
            break;
        case '1' ... '9':
            columna = 1;
            break;
        case '(':
            columna = 3;
            break;
		case ')':
            columna = 4;
            break;
        case '*': case '+': case '-': case '/':     // se ordenaron asi, por su secuencia en ASCII
            columna = 2;
            break;                                
        default:
            columna = 5;
            break;
	} return columna;
}

void mensaje (int columnaCaracter){
	switch (columnaCaracter) {
		case 0:
			submensaje (1); 
				submensaje (2);
			break;
		case 1:
			submensaje (2);
			break;
		case 2:
			submensaje (1);
			break;
		case 3:
			submensaje (3);
				submensaje (2);
			break;
		case 4:
			submensaje (1);
				submensaje (3);
					submensaje (2);
			break;
        default :
            submensaje (4);
            break;
	}
}


void submensaje (int mensaje){
    switch (mensaje) {
        case 1:
            if (estadoActual == Q0)
                printf ("\n ERROR: en la posicion %d, se espera uno de [1-9,(] pero se recibio el caracter: %c \n", posicion, charEvaluado); 
            break;
        case 2:
            if (estadoActual == Q2 && cimaPila == 'R')
                printf ("\n ERROR: en la posicion %d, se espera uno de [+,-,*,/,)] pero se recibio el caracter: %c \n", posicion, charEvaluado); 
                else if (estadoActual == Q2 && cimaPila == '$')
                    printf ("\n ERROR: en la posicion %d, se espera uno de [+,-,*,/] pero se recibio el caracter: %c \n", posicion, charEvaluado); 
            break;
        case 3:
            if (estadoActual == Q1 && cimaPila == 'R')
                printf ("\n ERROR: en la posicion %d, se espera uno de [0-9,+,-,*,/,)] pero se recibio el caracter: %c \n", posicion, charEvaluado); 
                else if (estadoActual == Q1 && cimaPila == '$')
                    printf ("\n ERROR: en la posicion %d, se espera uno de [0-9,+,-,*,/] pero se recibio el caracter: %c \n", posicion, charEvaluado); 
            break;
        default :
            printf ("\n ERROR: La expresion esta incompleta. Se espera [0-9,(,)]. Caracter final: %c \n", charEvaluado);  
        break;
    }
}

void reset (){

    while (pila != NULL) {
        Nodo *nodo = pila;
        pila = nodo -> sgte;
        free(nodo);
    }						
    cimaPila = charEvaluado = '\0';
    columnaCaracter = estadoActual = posicion = '\0';
    expresion [0] = '\0';
}

void clearBuffer() {
  while(getchar() != '\n')
    ;
}


