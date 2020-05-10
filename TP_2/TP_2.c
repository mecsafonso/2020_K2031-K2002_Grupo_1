#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INICIAL 0
#define Q1 1
#define Q2 2
#define $ 0
#define R 1
typedef struct nodo{
        char info;
        struct nodo * sgte;
    } elemento;

void push (elemento * , char);
char pop (elemento *);

int main (){
    elemento * pila = NULL;
    push (pila, '$');

    typedef struct proxEstado {
        int estado;
        char cimaPila;
    } proximoEstado;

    proximoEstado * inicialVacio, *inicialLleno, *parentecisVacio, *parentecisLleno, *q1Vacio, *q1Lleno, *q2Vacio, *q2Lleno, *cierroParentesis, *rechazado;
    inicialVacio -> estado = inicialLleno -> estado = parentecisVacio -> estado = parentecisLleno -> estado = INICIAL;
    q1Vacio -> estado = q1Lleno -> estado = Q1;
    q2Vacio -> estado = q2Lleno -> estado = cierroParentesis -> estado = Q2;
    inicialVacio -> cimaPila = q1Vacio -> cimaPila = q2Vacio -> cimaPila = '$';
    inicialLleno -> cimaPila = q1Lleno -> cimaPila = q2Lleno -> cimaPila ='R';
    parentecisVacio -> cimaPila = 'R$';
    parentecisLleno -> cimaPila = 'RR';
    cierroParentesis -> cimaPila = NULL;


    proximoEstado * tablaDeTransicion [3] [2] [5];
    
    tablaDeTransicion [INICIAL] [$] [0] = rechazado;
    tablaDeTransicion [INICIAL] [$] [1] = q1Vacio;
    tablaDeTransicion [INICIAL] [$] [2] = rechazado;
    tablaDeTransicion [INICIAL] [$] [3] = parentecisVacio;
    tablaDeTransicion [INICIAL] [$] [4] = rechazado;
    tablaDeTransicion [INICIAL] [R] [0] = rechazado;
    tablaDeTransicion [INICIAL] [R] [1] = q1Lleno;
    tablaDeTransicion [INICIAL] [R] [2] = rechazado;
    tablaDeTransicion [INICIAL] [R] [3] = parentecisLleno;
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

    
    printf ("Introdusca una expresión aritmetica:");
    char expresion [50];
    scanf ("%s\n", expresion);

    int i = 0;
    int caracter, cimaP;
    int estadoActual = INICIAL;
    char evaluado, proxCima;
    proximoEstado * bloqueActual;
    
    while (expresion [i] != "\0")
    {
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

            if (pop (pila) == "$"){
                cimaP = $;
            } else {
                cimaP = R;
            }

            bloqueActual = tablaDeTransicion [estadoActual] [cimaP] [caracter];
        
            if (bloqueActual == rechazado){
                break;
            }

            estadoActual = bloqueActual -> estado;
      
            proxCima = bloqueActual -> cimaPila,
            push (pila, proxCima );
            }
        
        i++;        
        
    }

    switch (pop (pila))
    {
    case $:
        if (estadoActual == Q2 || estadoActual == Q1){
            scanf ("La expresión %s es sintacticamente correcta \n", expresion);
            break;
        }  
    
    default:
        scanf ("La expresión %s no es sintacticamente correcta \n", expresion);
        break;
    }
    
  
    return 0;
}

void push (elemento* pila, char x){
    elemento * nuevo;
    nuevo -> info = x;
    nuevo -> sgte = pila;
    pila = nuevo;
}

char pop (elemento * pila){
    elemento * p = pila;
    char x = p -> info;
    pila = p -> sgte;
    free (p -> info);
    free (p);
    return x; 
}