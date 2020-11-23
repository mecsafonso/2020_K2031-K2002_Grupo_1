#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>  

#define BASE8 8
#define BASE16 16

typedef struct nodoInfo{
    char info[30];
    struct nodoInfo* sig;
}nodoInfo;

typedef struct {
    char identificador[30];
    char tipo[30];
    int es_funcion;
    nodoInfo* listaParametros;
} funcion;

typedef struct nodo{
    funcion info;
    struct nodo* sig;
} nodo;

typedef struct nodoErroresSintacticos{
    int linea;
    struct nodoErroresSintacticos* sig;
}nodoErroresSintacticos;

typedef struct nodoError{
    char* info;
    int linea;
    struct nodoError* sig;
}nodoError;

void agregar_info(nodoInfo** listaParametros, char tipo[]);
void agregar_validaciones_sintacticas(nodoError** listaParametros, int nroLinea , char* mensaje);
void agregar_error_sintactico(nodoErroresSintacticos** listaParametros, int nroLinea);
void agregar_error_lexico(nodoError** lista, char* error, int nroLinea);
void agregar_nodo_error(nodoError** lista, char* error, int nroLinea);
int agregar_variable(nodo** lista, char nombre[], char tipo[]);
void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros);

int control_tipos(char palabra[], char tipo[]);
nodo* existe_variable(nodo* lista, char nombre[]);
char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal);
void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros);
void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal);
void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal);
void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal);
int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal);

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal);
void imprimir_lista_variables(nodo* lista, FILE* archivoFinal);
void imprimir_funciones(nodo* lista, FILE* archivoFinal);
void imprimir_validaciones_sintacticas(nodoError** lista, FILE* archivoFinal);
void imprimir_errores_sintacticos(nodoErroresSintacticos** lista, FILE* archivoFinal);
void imprimir_errores(nodoError** lista, FILE* archivoFinal);
void imprimir_nodo_error(nodoError** lista, FILE* archivoFinal);

int caracterHexadecimalADecimal(char);
int convertirAdecimal(char*, int, int);

extern nodoError* listaErroresLexicos;
