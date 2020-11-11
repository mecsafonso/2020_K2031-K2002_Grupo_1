%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//#include "TP4.h"

#include <stdlib.h>

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

int control_tipos(char palabra[], char tipo[]);
nodo* existe_variable(nodo* lista, char nombre[]);
char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal);
void agregar_parametro(nodoInfo** listaParametros, char tipo[]);
int agregar_variable(nodo** lista, char nombre[], char tipo[]);
void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros);
void agregar_error(nodoInfo* lista, char error[]);
void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal);
void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal);
void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal);
int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal);
//void eliminar_ultimo(nodoVariable* listavariables);
//void pasar_a_lista_parametros(nodoVariable* listaParametros, nodoVariable* listavariables, int cantidad);

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal);
void imprimir_lista_variables(nodo* lista, FILE* archivoFinal);
void imprimir_funciones(nodo* lista, FILE* archivoFinal);
void imprimir_errores(nodoInfo** lista, FILE* archivoFinal);

#define YYDEBUG 1
extern FILE *yyin;
extern FILE *yyout;

int flag_error=0;
int contador=0;
char tipo[30];
char identificador[30];
char tipo_parametro[30];
int modo_funcion = 0;
int contador_parametros = 0;
nodo* listaVariables = NULL;
nodoInfo* listaErroresLexicos = NULL;
nodoInfo* listaParametros = NULL;

FILE* archivoFinal;

int yylex();

int yywrap(){
	return(1);
}

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}

%}

%union {
char cadena[30];
int entero;
int tipo;
float real;
}

%token <entero> NUM
%token <real> CONS_REAL
%token <cadena> IDENTIFICADOR
%token <cadena> ESPECIFICADOR_TIPO
%token <entero> error
%token <cadena> LIT_CADENA
%token <cadena> CARACTER
%token <cadena> FOR
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> SWITCH
%token <cadena> GOTO
%token <cadena> CONTINUE
%token <cadena> BREAK
%token <cadena> CASE
%token <cadena> DEFAULT
%token <cadena> RETURN
%token <cadena> IF
%token <cadena> ELSE
%token <cadena> SIZEOF
%token <cadena> STRUCT
%token <cadena> UNION
%token <cadena> CONST
%token <cadena> VOLATILE
%token <cadena> ENUM
%token <cadena> OPER_ASIGNACION
%token <cadena> OPER_OR
%token <cadena> OPER_AND
%token <cadena> OPER_IGUALDAD
%token <cadena> OPER_DIFERENCIA
%token <cadena> OPER_RELACIONAL
%token <cadena> OPER_INC_DEC
%token <cadena> OPER_NEGACION
%token <cadena> OPER_DIRECCION
%token <cadena> ESPECIFICADOR_ALMACENAMIENTO


%% 

input:    
  | input line
;

line: '\n'  {fprintf(archivoFinal,"\n--------------------------------------- \n \n");}
  | sentencia '\n'    {fprintf(archivoFinal,"\n-----------------SENTENCIA---------------- \n \n");}
  | declaracion '\n'  {fprintf(archivoFinal,"\n-----------------DECLARACION---------------- \n \n");}
;




declaracion: especificadoresDeclaracion listaDeclaradoresOP ';' {fprintf(archivoFinal,"se encontro una declaracion \n");memset(tipo, 0, 30);}
  | especificadoresDeclaracion listaDeclaradoresOP sentCompuesta {fprintf(archivoFinal,"se encontró una desarrollo de función");memset(tipo, 0, 30);}
;

/* En la segunda linea se va a el desarrollo de una funcion, sin embargo esta puede escribirse como int asd(a,b){} debido a listaIdentificadoresOP, */
/* como el compilador no da error sino un warning, se decidió dejarlo así */

listaDeclaradoresOP: {memset(tipo, 0, 30);}
  | listaDeclaradores
;

especificadoresDeclaracion: especificadorClaseAlmacenamiento especificadoresDeclaracionOP
  | especificadorTipo especificadoresDeclaracionOP
  | calificadorTipo especificadoresDeclaracionOP
;

especificadoresDeclaracionOP: 
  | especificadoresDeclaracion
;

listaDeclaradores: declarador
  | listaDeclaradores ',' declarador {fprintf(archivoFinal,"se encontro mas de una declaracion \n");}
;

declarador: decla
  | decla OPER_ASIGNACION inicializador {fprintf(archivoFinal,"se encontro una asignacion \n");}
;

inicializador: expAsignacion 
  | '{' listaInicializadores '}'
  | '{' listaInicializadores ',' '}'
;

listaInicializadores: inicializador
  | listaInicializadores ',' inicializador
;

especificadorClaseAlmacenamiento: ESPECIFICADOR_ALMACENAMIENTO {if(tipo[0] == '\0'){strcpy(tipo, $<cadena>1);};}
;

especificadorTipo: ESPECIFICADOR_TIPO {strcpy(tipo, $<cadena>1) ;fprintf(archivoFinal, "se encontro el tipo de dato %s \n", tipo);}
  | especificadorStructOUnion 
  | especificadorEnum 
;



calificadorTipo: CONST {if(tipo[0] == '\0'){strcpy(tipo, $<cadena>1);};}
  | VOLATILE {if(tipo[0] == '\0'){strcpy(tipo, $<cadena>1);};}
;

especificadorStructOUnion: structOUnion identificadorOP '{' listaDeclaracionesStruct '}'
  | structOUnion IDENTIFICADOR {strcpy(tipo, $<cadena>2);} 
;

identificadorOP: 
  | IDENTIFICADOR {strcpy(tipo, $<cadena>1);} 
;

structOUnion: STRUCT
  | UNION
;

listaDeclaracionesStruct: declaracionStruct ';'
  | listaDeclaracionesStruct declaracionStruct
;

declaracionStruct: listaCalificadores declaradoresStruct ';'
;

listaCalificadores: especificadorTipo listaCalificadoresOP
  | calificadorTipo listaCalificadoresOP
;

listaCalificadoresOP: 
  | listaCalificadores
;

declaradoresStruct: declaStruct
  | declaradoresStruct ',' declaStruct
;

declaStruct: decla
  | declaOP ':' expConstante
;

decla: punteroOP declaradorDirecto
;

declaOP: 
  | decla
;

puntero: '*' listaCalificadoresTiposOP {strcat(tipo, "*");}
  | '*' listaCalificadoresTiposOP puntero
;

punteroOP: 
  | puntero
;

listaCalificadoresTipos: calificadorTipo 
  | listaCalificadoresTipos calificadorTipo
;

listaCalificadoresTiposOP: 
  | listaCalificadoresTipos
;

declaradorDirecto: IDENTIFICADOR {gestionar_identificador(&listaVariables, $<cadena>1, tipo, archivoFinal);}
  | '(' decla ')'
  | IDENTIFICADOR '[' expConstanteOP ']' {gestionar_identificador(&listaVariables, $<cadena>1, tipo, archivoFinal);}
  | IDENTIFICADOR '(' listaTiposParametros ')' {gestionar_funcion(&listaVariables, listaParametros,$<cadena>1, tipo, archivoFinal);listaParametros = NULL;fprintf(archivoFinal, "se encontro una funcion \n");}
  | IDENTIFICADOR '(' listaIdentificadoresOP ')' {gestionar_funcion(&listaVariables, listaParametros,$<cadena>1, tipo, archivoFinal);listaParametros = NULL; fprintf(archivoFinal, "se encontro una funcion \n");}
	| error {flag_error=1;fprintf(archivoFinal,"error xd \n");}
;

listaTiposParametros: listaParametros
  | listaParametros ',' '.' '.' '.'
;

listaTiposParametrosOP: 
  | listaTiposParametros
;

listaParametros: declaracionParametro 
  | listaParametros ',' declaracionParametro
;

declaracionParametro: especificadoresDeclaracionParametro punteroParametroOp declaParametro {agregar_parametro(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);}
  | especificadoresDeclaracionParametro punteroParametroOp declaradorAbstractoDirectoOP {agregar_parametro(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);}
;

especificadoresDeclaracionParametro: ESPECIFICADOR_TIPO especificadoresDeclaracionParametroOp {strcpy(tipo_parametro, $<cadena>1);}
  | CONST especificadoresDeclaracionParametroOp {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, $<cadena>1);};}
  | VOLATILE especificadoresDeclaracionParametroOp {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, $<cadena>1);};}
;

especificadoresDeclaracionParametroOp:
  |especificadoresDeclaracionParametro
;

punteroParametroOp:
  |'*' {strcat(tipo_parametro, "*");}
;

declaParametro: IDENTIFICADOR
  | '(' punteroParametroOp declaParametro ')'
  | IDENTIFICADOR '[' expConstanteOP ']'
	| error {flag_error=1;fprintf(archivoFinal,"error xd \n");}
;

listaIdentificadores: IDENTIFICADOR {agregar_parametro(&listaParametros, "int");}
  | listaIdentificadores ',' IDENTIFICADOR {agregar_parametro(&listaParametros, "int");}
;

listaIdentificadoresOP: 
  | listaIdentificadores
;

especificadorEnum: ENUM identificadorOP '{' listaEnumeradores '}'
  | ENUM IDENTIFICADOR {strcpy(tipo, $<cadena>2);}
;

listaEnumeradores: enumerador
  | listaEnumeradores ',' enumerador
;

enumerador: constanteEnumeracion
  | constanteEnumeracion OPER_ASIGNACION expConstante
;

constanteEnumeracion: IDENTIFICADOR
;

nombreTipo: listaCalificadores punteroParametroOp declaradorAbstractoDirectoOP
;

declaradorAbstractoDirecto: '(' punteroParametroOp declaradorAbstractoDirectoOP ')'
  | declaradorAbstractoDirectoOP '[' expConstanteOP ']'
  | declaradorAbstractoDirectoOP '(' listaTiposParametrosOP ')'
;

declaradorAbstractoDirectoOP: 
  | declaradorAbstractoDirecto
;










expresion: expAsignacion {memset(tipo, 0, 30);}
  | expresion ',' expAsignacion
;

expresionOP: 
  | expresion
;

expAsignacion: expCondicional
  | expUnaria operAsignacion expAsignacion
;

operAsignacion: OPER_ASIGNACION
;

expConstante: expCondicional
;

expConstanteOP: 
  | expConstante
;

expCondicional: expOr 
;


expOr: expAnd
  | expOr OPER_OR expAnd    {fprintf(archivoFinal,"se encontro una expresion OR \n");}
;

expAnd: expIgualdad
  | expAnd OPER_AND expIgualdad   {fprintf(archivoFinal,"se encontro una expresion AND \n");}
;

expIgualdad: expRelacional
  | expIgualdad OPER_IGUALDAD expRelacional   {fprintf(archivoFinal,"se encontro una expresion de IGUALDAD \n");}
  | expIgualdad OPER_DIFERENCIA expRelacional   {fprintf(archivoFinal,"se encontro una expresion de DIFERENCIA \n");}
;

expRelacional: expAditiva
  | expRelacional OPER_RELACIONAL expAditiva    {fprintf(archivoFinal,"se encontro una expresion RELACIONAL \n");}
;

expAditiva: expMultiplicativa
  | expAditiva '+' expMultiplicativa    {fprintf(archivoFinal,"se encontro una expresion de SUMA \n");}
  | expAditiva '-' expMultiplicativa    {fprintf(archivoFinal,"se encontro una expresion de RESTA \n");}
;

expMultiplicativa: expUnaria
  | expMultiplicativa '*' expUnaria     {fprintf(archivoFinal,"se encontro una expresion de MULTIPLICACION \n");}
  | expMultiplicativa '/' expUnaria     {fprintf(archivoFinal,"se encontro una expresion de DIVISION \n");}
  | expMultiplicativa '%' expUnaria     {fprintf(archivoFinal,"se encontro una expresion de RESTO \n");}
;

expUnaria: expPostfijo
  | OPER_INC_DEC expUnaria
  | operUnario expUnaria
  | SIZEOF '(' nombreTipo ')'
;

operUnario: OPER_DIRECCION
  |'*'
  |'-'
  |'+'
  |OPER_NEGACION
;

expPostfijo: expPrimaria
  | expPostfijo '[' expresion ']'
  | IDENTIFICADOR '(' listaArgumentosOP ')' {sentencia_funcion(&listaVariables, listaParametros, $<cadena>1, archivoFinal);}
;

listaArgumentosOP:
  | listaArgumentos
;


listaArgumentos: argumento
  | listaArgumentos ',' argumento
;

argumento: IDENTIFICADOR {agregar_parametro(&listaParametros, tipo_variable(listaVariables, $<cadena>1, archivoFinal));}
  | NUM {agregar_parametro(&listaParametros, "int");}
  | CONS_REAL {agregar_parametro(&listaParametros, "float");}
  | LIT_CADENA {agregar_parametro(&listaParametros, "char*");}
;

expPrimaria: IDENTIFICADOR {char* comparar_tipo = tipo_variable(listaVariables, $<cadena>1, archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo[0] == '\0'){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s\n", comparar_tipo, tipo);}}}
  | NUM {if(tipo[0] == '\0'){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s\n", tipo);}}
  | CONS_REAL {if(tipo[0] == '\0'){strcpy(tipo, "float");}else if(!control_tipos(tipo, "float")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un float y un %s\n", tipo);}}
  | LIT_CADENA {if(tipo[0] == '\0'){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s\n", tipo);}}
  | '(' expresion ')'
  | error {flag_error=1;fprintf(archivoFinal,"Expresion unaria no valida \n");}
;



















sentencia: sentCompuesta
  | sentExpresion {fprintf(archivoFinal,"se encontro una expresion \n");}
  | sentSeleccion {fprintf(archivoFinal,"se encontro un sentencia de seleccion \n");}
  | sentIteracion {fprintf(archivoFinal,"se encontro un sentencia de iteracion \n");}
  | sentEtiquetada {fprintf(archivoFinal,"se encontro un sentencia etiquetada \n");}
  | sentSalto {fprintf(archivoFinal,"se encontro un sentencia de salto \n");}
;

sentCompuesta: '{' listaDeclaracionesOP listaSentenciasOP '}' {fprintf(archivoFinal,"se encontro una sentencia compuesta \n");}
;

listaDeclaraciones: declaracion 
  | listaDeclaraciones declaracion
;

listaDeclaracionesOP:
  | listaDeclaraciones
;


listaSentencias: sentencia
  | listaSentencias sentencia
;

listaSentenciasOP: 
  | listaSentencias
;

sentExpresion: expresionOP ';'
;

sentSeleccion: IF '(' expresion ')' sentencia  
  | IF '(' expresion ')' sentencia ELSE sentencia  
  | SWITCH '(' expresion ')' sentencia 
;

sentIteracion: WHILE '(' expresion ')' sentencia
  | DO sentencia WHILE '(' expresion ')' ';'
  | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia
;

sentEtiquetada: CASE  expresion ':' sentencia
  | DEFAULT ':' sentencia
  | IDENTIFICADOR ':' sentencia
;

sentSalto: RETURN expresionOP ';'
  | CONTINUE ';'
  | BREAK ';'
  | GOTO IDENTIFICADOR ';'
;






%%

int main ()
{
  yyin = fopen("entrada.txt", "r");
  yyout = fopen("salida.txt", "w");
  archivoFinal = fopen("Informe.txt", "w");


  yyparse();
  yylex();

  imprimir_lista_variables(listaVariables, archivoFinal);
  imprimir_funciones(listaVariables, archivoFinal);
  imprimir_errores(&listaErroresLexicos, archivoFinal);

  fclose(archivoFinal);
  return 0;
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG

}

int control_tipos(char palabra[], char tipo[]) {
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  if(!strcmp(tipo, "char") && !strcmp(palabra, "char")){
    return 1;
  }
  if(!strcmp(tipo, "char*") && !strcmp(palabra, "char*")){
    return 1;
  }
  if(!strcmp(tipo, "void*") || !strcmp(tipo, "char*") || !strcmp(tipo, "int*") && !strcmp(palabra, "void*")){
    return 1;
  }
  if((!strcmp(tipo, "const") || !strcmp(tipo, "volatile") || !strcmp(tipo, "typedef")) && (!strcmp(palabra, "int"))){
    return 1;
  }
  return 0;
}

nodo* existe_variable(nodo* lista, char nombre[]){
    nodo* aux = lista;
    while(aux){
        if(!strcmp(aux->info.identificador, nombre)){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal){
  nodo* variable = existe_variable(lista, nombre);
  if(variable == NULL){
    fprintf(arcFinal, "La variable %s no fue declarada\n", nombre);
    return "error";
  } 
  return variable->info.tipo;
}

void agregar_parametro(nodoInfo** listaParametros, char tipo[]){
  nodoInfo* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoInfo));
    strcpy((*listaParametros)->info, tipo);
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoInfo));
  strcpy(aux->sig->info, tipo);
  aux->sig->sig = NULL;
  return;
}

int agregar_variable(nodo** lista, char nombre[], char tipo[]){
    if(existe_variable(*lista, nombre) != NULL){
        return 0;
    }
    nodo* aux = (*lista);
    while(aux != NULL && aux->sig != NULL){
        aux = aux->sig;
    }
    if(aux == NULL){
      (*lista) = malloc(sizeof(nodo));
      (*lista)->info.es_funcion = 0;
      (*lista)->info.listaParametros = NULL;
      strcpy((*lista)->info.identificador, nombre);
      strcpy((*lista)->info.tipo, tipo);
      (*lista)->sig = NULL;
      return 1;
    }
    aux->sig = malloc(sizeof(nodo));
    strcpy(aux->sig->info.identificador, nombre);
    strcpy(aux->sig->info.tipo, tipo);
    aux->sig->info.es_funcion = 0;
    aux->sig->info.listaParametros = NULL;
    aux->sig->sig = NULL;
    return 1;
}

void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros){
    nodo* aux = (*lista);
    while(aux != NULL && aux->sig != NULL){
        aux = aux->sig;
    }
    if(aux == NULL){
      (*lista) = malloc(sizeof(nodo));
      (*lista)->info.es_funcion = 1;
      (*lista)->info.listaParametros = listaParametros;
      strcpy((*lista)->info.identificador, nombre);
      strcpy((*lista)->info.tipo, tipo);
      (*lista)->sig = NULL;
      return;
    }
    aux->sig = malloc(sizeof(nodo));
    strcpy(aux->sig->info.identificador, nombre);
    strcpy(aux->sig->info.tipo, tipo);
    aux->sig->info.es_funcion = 1;
    aux->sig->info.listaParametros = listaParametros;
    aux->sig->sig = NULL;
}

void agregar_error(nodoInfo* lista, char error[]){
    nodoInfo* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info, error);
    aux->sig = NULL;
}

void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal){
    if(!agregar_variable(listaVariables, nombre, tipo)){
      fprintf(archivoFinal, "Doble declaración de la variable: %s \n", nombre);
    }    
}

void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal){
    nodo* aux = existe_variable(*lista, identificador);
    if(aux == NULL){
        agregar_funcion(lista, identificador, tipo, listaParametros);
    } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
    }
}

void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal){
  nodo* aux = existe_variable(*lista, identificador);
    if(aux == NULL){
        fprintf(archivoFinal, "La funcion %s no fue declarada\n", identificador);
    } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
    }
}

int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal){
  nodoInfo* auxLista = funcion->info.listaParametros;
  nodoInfo* auxParam = listaParametros;
  int contador_parametros = 0;
  while(auxParam != NULL && auxLista != NULL){
    if(!control_tipos(auxParam->info, auxLista->info)){
      fprintf(archivoFinal, "La funcion %s esperaba una variable de tipo %s como parametro %d, pero recibio %s\n", funcion->info.identificador, auxLista->info, contador_parametros, auxParam->info);
      return 0;
    }
    auxLista = auxLista->sig;
    auxParam = auxParam->sig;
  }
  if(auxLista != NULL){
    fprintf(archivoFinal, "La funcion %s esperaba mas parametros de los recibidos\n", funcion->info.identificador); 
    return 0;
  } 
  if (auxParam != NULL){
    fprintf(archivoFinal, "La funcion %s recibio menos parametros de los esperados\n", funcion->info.identificador);     
  }
  return 1;
}

/*void eliminar_ultimo(nodoVariable* listavariables){
    nodoVariable* aux = listavariables;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    free(aux->info.identificador);
    free(aux->info.tipo);
    aux = NULL;
}*/
/*
void pasar_a_lista_parametros(nodoVariable* listaParametros, nodoVariable* listavariables, int cantidad){
  if(cantidad <= 0){
      return;
  }
  nodoVariable* aux = listavariables;
  while(aux->sig != NULL){
    aux = aux->sig;
  }
  strcpy(listaParametros->info.identificador, aux->info.identificador);
  strcpy(listaParametros->info.tipo, aux->info.tipo);
  free(aux->info.identificador);
  free(aux->info.tipo);
  free(aux);

  cantidad--;
  nodoVariable* auxParam = NULL;
  listaParametros->sig = auxParam; 
  while(cantidad > 0){
    auxParam = malloc(sizeof(*auxParam));
    aux = listavariables;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    strcpy(auxParam->info.identificador, aux->info.identificador);
    strcpy(auxParam->info.tipo, aux->info.tipo);
    auxParam->sig = NULL;
    auxParam = auxParam->sig;
    free(aux->info.identificador);
    free(aux->info.tipo);
    aux = NULL;
  }
}*/

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal){
  nodoInfo* aux = lista;
  int i = 0;
  while(aux != NULL){
    fprintf(archivoFinal, "\t\t\tIdentificador N°: %d\t Tipo: %s\n", i, aux->info);
    aux = aux->sig;
    i++;
  }
}

void imprimir_lista_variables(nodo* lista, FILE* archivoFinal){
  fprintf(archivoFinal, "---------------------------------- VARIABLES ----------------------------------\n");
  nodo* aux = lista;
  while(aux != NULL){
    if(aux->info.es_funcion == 0){
      fprintf(archivoFinal, "Identificador: %s\t Tipo: %s\n", aux->info.identificador, aux->info.tipo);
    }
    aux = aux->sig;
  }
}

void imprimir_funciones(nodo* lista, FILE* archivoFinal){
  nodo* aux = lista;
  fprintf(archivoFinal, "---------------------------------- FUNCIONES ----------------------------------\n");
  while(aux != NULL){
    if(aux->info.es_funcion == 1){
      fprintf(archivoFinal, "IDENTIFICADOR: %s\n\t Tipo Retorno: %s\n\t Parametros:\n", aux->info.identificador, aux->info.tipo);
      imprimir_parametros(aux->info.listaParametros, archivoFinal);
    }    
    aux = aux->sig;
  }
}

void imprimir_errores(nodoInfo** lista, FILE* archivoFinal){
  nodoInfo* aux;
  fprintf(archivoFinal, "---------------------------------- ERRORES LEXICOS ----------------------------------\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "%s\n", aux->info);
    (*lista) = aux->sig;
    free(aux->info);
    free(aux);
  }
}