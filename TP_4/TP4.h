#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char identificador[30];
  char tipo[30];
  //void* valor;
} variable;

typedef struct nodoVariable{
    variable info;
    struct nodoVariable* sig;
} nodoVariable;

typedef struct{
    char identificador[30];
    char tipo[30];
    variable* listaParametros;
} funcion;

typedef struct nodoFuncion{
    funcion info;
    struct nodoFuncion* sig;
} nodoFuncion;


typedef struct nodoErrorLexico{
    char info[30];
    struct nodoError* sgt;
}nodoErrorLexico;

nodoFuncion* listaFunciones = NULL;
nodoErrorLexico* listaErroresLexicos = NULL;



int control_tipos(char palabra[], char tipo[]) {
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  else if(!strcmp(tipo, "char") && !strcmp(palabra, "char")){
    return 1;

// 




















remover y copiarla en la ista de parametros
nodoVariabñe* listaParametros = NULL;ESPECIFICADOR_TIPO

/// IDEA DANI (que tubo gracias al dibujito magnifico de Sol);
        // Copiar todas las variables de parametros a la lnodoFuncion* listaFunciones = NULL;
nodoErrorLexico* listaErroresLexicos = NULL;

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

int existe_variable(nodoVariables* lista, char nombre[30]){
    nodoVariable* aux = lista;
    while(aux){
        if(!strcmp(lista->info.identificador, nombre)){
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
}

int existe_funcion(nodoFuncion* lista, char nombre[30]){
    nodoFuncion* aux = lista;
    while(lista){
        if(!strcmp(lista->info.identificador, nombre)){
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
}

int agregar_variable(nodoVariables* lista, char nombre[30], char tipo[30]){
    if(existe_variable(lista, nombre)){
        return 0;
    }
    nodoVariable* aux = lista;
    while(aux){
        aux = aux->sig;
    }
    strcpy(aux->identificador, nombre);
    strcpy(aux->tipo, tipo);

    return 1;
}

int agregar_funcion(nodoFuncion* lista, char nombre[30], char tipo[30]){
    nodoFuncion* aux = lista;
    while(aux){
        aux = aux->sig;
    }
    strcpy(aux->identificador, nombre);
    strcpy(aux->tipo, tipo);
}
