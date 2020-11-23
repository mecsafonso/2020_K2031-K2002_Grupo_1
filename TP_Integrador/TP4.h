#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoDeErroresLexicos{
    char info[30];
    int linea;
    struct nodoDeErroresLexicos* sig;
}nodoDeErroresLexicos;



extern nodoDeErroresLexicos* listaErroresLexicos;

void agregar_error_lexico(nodoDeErroresLexicos** lista, char* error, int nroLinea);

void imprimir_errores(nodoDeErroresLexicos** lista, FILE* archivoFinal);
/*

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


int control_tipos(char palabra[], char tipo[]);
nodo* existe_variable(nodo* lista, char nombre[]);
char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal);
void agregar_info(nodoInfo** listaParametros, char tipo[]);
int agregar_variable(nodo** lista, char nombre[], char tipo[]);
void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros);
void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal);
void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal);
void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal);
int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal);

void agregar_error(nodoInfo* lista, char error[]);

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal);
void imprimir_lista_variables(nodo* lista, FILE* archivoFinal);
void imprimir_funciones(nodo* lista, FILE* archivoFinal);
void imprimir_errores(nodoInfo** lista, FILE* archivoFinal);
*/



