#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char identificador[30];
    char tipo[30];
    int es_funcion;
    nodo* listaParametros;
} funcion;
typedef struct nodo{
    funcion info;
    struct nodo* sig;
} nodo;

typedef struct nodoError{
    char info[30];
    struct nodoError* sig;
}nodoError;

int control_tipos(char palabra[], char tipo[]);
nodo* existe_variable(nodo* lista, char nombre[]);
char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal);
int agregar_variable(nodo* lista, char nombre[], char tipo[]);
int agregar_funcion(nodo* lista, char nombre[], char tipo[], nodo* listaParametros);
void agregar_error(nodoError* lista, char error[]);
void gestionar_identificador(nodo* listaVariables, char nombre[], char tipo[], FILE* archivoFinal);
void gestionar_funcion(nodo* lista, nodo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal);
int parametros_contra_funcion(nodo* funcion, nodo* listaParametros, FILE* archivoFinal);
void vaciar_parametros(nodo* listaParametros);
//void eliminar_ultimo(nodoVariable* listavariables);
//void pasar_a_lista_parametros(nodoVariable* listaParametros, nodoVariable* listavariables, int cantidad);

void imprimir_parametros(nodo* lista, FILE* archivoFinal);
void imprimir_lista_variables(nodo* lista, FILE* archivoFinal);
void imprimir_funciones(nodo* lista, FILE* archivoFinal);
void imprimir_errores(nodoError* lista, FILE* archivoFinal);






/*
//remover y copiarla en la ista de parametros
ESPECIFICADOR_TIPO

/// IDEA DANI (que tubo gracias al dibujito magnifico de Sol);
        // Copiar todas las variables de parametros a la lnodoFuncion* listaFunciones = NULL;


typedef struct nodoErrorLexico{
    char info[30];
    struct nodoError* sgt;
}nodoErrorLexico;

especificadorTipo: ESPECIFICADOR_TIPO {{strcpy(tipo, $<cadena>1)} fprintf(archivoFinal, "se encontro el tipo de dato %s \n", $<cadena>1);}
  | especificadorStructOUnion
  | especificadorEnum
;


especificadorStructOUnion: structOUnion identificadorOP '{' listaDeclaracionesStruct '}'
  | structOUnion IDENTIFICADOR {strcpy(tipo, $<cadena>2)}
;

identificadorOP: 
  | IDENTIFICADOR {strcpy(tipo, $<cadena>1)}
;

especificadorClaseAlmacenamiento: ESPECIFICADOR_ALMACENAMIENTO {if(tipo[0]== '\0'){strcpy(tipo, $<cadena>1)}}

declaradorDirecto: IDENTIFICADOR {{} fprintf(archivoFinal,"se encontro declaradorDirecto %s \n", $<cadena>1);}
  | '(' decla ')'
  | declaradorDirecto '[' expConstanteOP ']'
  | declaradorDirecto '(' listaTiposParametros ')' {fprintf(archivoFinal,"se encontró una firma de función")}
  | declaradorDirecto '(' listaIdentificadoresOP ')'
	| error {flag_error=1;fprintf(archivoFinal,"error xd \n");}
;

calificadorTipo: CONST {if(tipo[0]== '\0'){strcpy(tipo, $<cadena>1)}}
  | VOLATILE {if(tipo[0]== '\0'){strcpy(tipo, $<cadena>1)}}
;

////  TP4.h
*/
