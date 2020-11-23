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

typedef struct nodoErroresSintacticos{
    int linea;
    struct nodoErroresSintacticos* sig;
}nodoErroresSintacticos;

typedef struct nodoValidacionesSintacticas{
    char info[100];
    int linea;
    struct nodoValidacionesSintacticas* sig;
}nodoValidacionesSintacticas;


int control_tipos(char palabra[], char tipo[]);
nodo* existe_variable(nodo* lista, char nombre[]);
char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal);
void agregar_info(nodoInfo** listaParametros, char tipo[]);
void agregar_validaciones_sintacticas(nodoValidacionesSintacticas** listaParametros, int nroLinea , char mensaje[]);
void agregar_error_sintactico(nodoErroresSintacticos** listaParametros, int nroLinea);
int agregar_variable(nodo** lista, char nombre[], char tipo[]);
void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros);
void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal);
void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal);
void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal);
int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal);

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal);
void imprimir_lista_variables(nodo* lista, FILE* archivoFinal);
void imprimir_funciones(nodo* lista, FILE* archivoFinal);
void imprimir_validaciones_sintacticas(nodoValidacionesSintacticas** lista, FILE* archivoFinal);
void imprimir_errores(nodoInfo** lista, FILE* archivoFinal);
void imprimir_errores_sintacticos(nodoErroresSintacticos** lista, FILE* archivoFinal);


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
nodoErroresSintacticos* listaErroresSintacticos = NULL;
nodoValidacionesSintacticas* listaDeValidacionesSintacticas = NULL;


FILE* archivoFinal;

int yylex();

int yywrap(){
	return(1);
}

int numeroDeLinea = 1;

void yyerror (char const *s) {
  agregar_error_sintactico(&listaErroresSintacticos, numeroDeLinea);
}

%}

%union {
char cadena[30];
int entero;
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

input: /* vacío */
  | input line
  | error caracterDeCorte {flag_error==0;} 
;

line: '\n'  {fprintf(archivoFinal,"");flag_error=0; numeroDeLinea++;}
  | sentencia '\n'    {fprintf(archivoFinal,"");flag_error==0; numeroDeLinea++;}
  | declaracion '\n'  {fprintf(archivoFinal,"");flag_error==0; numeroDeLinea++;}
; /* \n-----------------SENTENCIA---------------- \n \n     \n-----------------DECLARACION---------------- \n \n  */

caracterDeCorte: ';' 
  | '\n' {numeroDeLinea++;}
;

declaracion: especificadoresDeclaracion listaDeclaradoresOP ';' {memset(tipo, 0, 30);}
  | especificadoresDeclaracion listaDeclaradoresOP sentCompuesta {memset(tipo, 0, 30);}
;
/* fprintf(archivoFinal,"se encontro una declaracion \n"); */

/* En la segunda linea se va a el desarrollo de una funcion, sin embargo esta puede escribirse como int asd(a,b){} debido a listaIdentificadoresOP, */
/* como el compilador no da error sino un warning, se decidió dejarlo así */

listaDeclaradoresOP: {memset(tipo, 0, 30);}
  | listaDeclaradores
;

especificadoresDeclaracion: especificadorClaseAlmacenamiento especificadoresDeclaracionOP
  | especificadorTipo especificadoresDeclaracionOP
  | calificadorTipo especificadoresDeclaracionOP
;

especificadoresDeclaracionOP: /* vacío */
  | especificadoresDeclaracion
;

listaDeclaradores: declarador
  | listaDeclaradores ',' declarador 
; /* {fprintf(archivoFinal,"se encontro mas de una declaracion \n");} */

declarador: decla
  | decla OPER_ASIGNACION inicializador  {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "ASIGNACION");}
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

especificadorTipo: ESPECIFICADOR_TIPO {strcpy(tipo, $<cadena>1)}
  | especificadorStructOUnion 
  | especificadorEnum 
; /* */ 

/* ;fprintf(archivoFinal, "se encontro el tipo de dato %s \n", tipo); */



calificadorTipo: CONST {if(tipo[0] == '\0'){strcpy(tipo, $<cadena>1);};}
  | VOLATILE {if(tipo[0] == '\0'){strcpy(tipo, $<cadena>1);};}
;

especificadorStructOUnion: structOUnion identificadorOP '{' listaDeclaracionesStruct '}'
  | structOUnion IDENTIFICADOR {strcpy(tipo, $<cadena>2);} 
;

identificadorOP: /* vacío */
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

listaCalificadoresOP: /* vacío */
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

declaOP: /* vacío */
  | decla
;

puntero: '*' listaCalificadoresTiposOP {strcat(tipo, "*");}
  | '*' listaCalificadoresTiposOP puntero
;

punteroOP: /* vacío */
  | puntero
;

listaCalificadoresTipos: calificadorTipo 
  | listaCalificadoresTipos calificadorTipo
;

listaCalificadoresTiposOP: /* vacío */
  | listaCalificadoresTipos
;

declaradorDirecto: IDENTIFICADOR {gestionar_identificador(&listaVariables, $<cadena>1, tipo, archivoFinal);}
  | '(' decla ')'
  | IDENTIFICADOR '[' expConstanteOP ']' {gestionar_identificador(&listaVariables, $<cadena>1, tipo, archivoFinal);}
  | IDENTIFICADOR '(' listaTiposParametros ')' {gestionar_funcion(&listaVariables, listaParametros,$<cadena>1, tipo, archivoFinal);listaParametros = NULL;}
  | IDENTIFICADOR '(' listaIdentificadoresOP ')' {gestionar_funcion(&listaVariables, listaParametros,$<cadena>1, tipo, archivoFinal);listaParametros = NULL;}
;

/* fprintf(archivoFinal, "se encontro una funcion \n"); */
/* 	| error {flag_error=1;fprintf(archivoFinal,"error con identificador %s \n", $<cadena>1);} */

listaTiposParametros: listaParametros
  | listaParametros ',' '.' '.' '.'
;

listaTiposParametrosOP: /* vacío */
  | listaTiposParametros
;

listaParametros: declaracionParametro 
  | listaParametros ',' declaracionParametro
;

declaracionParametro: especificadoresDeclaracionParametro punteroParametroOp declaParametro {agregar_info(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);}
  | especificadoresDeclaracionParametro punteroParametroOp declaradorAbstractoDirectoOP {agregar_info(&listaParametros, tipo_parametro); memset(tipo_parametro, 0, 30);}
;

especificadoresDeclaracionParametro: ESPECIFICADOR_TIPO especificadoresDeclaracionParametroOp {strcpy(tipo_parametro, $<cadena>1);}
  | CONST especificadoresDeclaracionParametroOp {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, $<cadena>1);};}
  | VOLATILE especificadoresDeclaracionParametroOp {if(tipo_parametro[0] == '\0'){strcpy(tipo_parametro, $<cadena>1);};}
;

especificadoresDeclaracionParametroOp: /* vacío */
  |especificadoresDeclaracionParametro
;

punteroParametroOp: /* vacío */
  |'*' {strcat(tipo_parametro, "*");}
;

declaParametro: IDENTIFICADOR
  | '(' punteroParametroOp declaParametro ')'
  | IDENTIFICADOR '[' expConstanteOP ']'
;


listaIdentificadores: IDENTIFICADOR {agregar_info(&listaParametros, "int");}
  | listaIdentificadores ',' IDENTIFICADOR {agregar_info(&listaParametros, "int");}
;

listaIdentificadoresOP: /* vacío */
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

declaradorAbstractoDirectoOP: /* vacío */
  | declaradorAbstractoDirecto
;










expresion: expAsignacion {memset(tipo, 0, 30);}
  | expresion ',' expAsignacion
;

expresionOP: /* vacío */
  | expresion
;

expAsignacion: expCondicional
  | expUnaria operAsignacion expAsignacion
;

operAsignacion: OPER_ASIGNACION
;

expConstante: expCondicional
;

expConstanteOP: /* vacío */
  | expConstante
;

expCondicional: expOr 
;


expOr: expAnd
  | expOr OPER_OR expAnd    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion OR");}
;

expAnd: expIgualdad
  | expAnd OPER_AND expIgualdad   {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion AND");}
;

expIgualdad: expRelacional
  | expIgualdad OPER_IGUALDAD expRelacional   {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion IGUALDAD");}
  | expIgualdad OPER_DIFERENCIA expRelacional    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion DIFERENCIA");}
;

expRelacional: expAditiva
  | expRelacional OPER_RELACIONAL expAditiva    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion RELACIONAL");}
;

expAditiva: expMultiplicativa
  | expAditiva '+' expMultiplicativa   {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion SUMA");}
  | expAditiva '-' expMultiplicativa   {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "expresion RESTA");}
;

expMultiplicativa: expUnaria
  | expMultiplicativa '*' expUnaria     {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación MULTIPLICACION con el tipo de dato %s \n", tipo);}}
  | expMultiplicativa '/' expUnaria     {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación DIVISION con el tipo de dato %s \n", tipo);}}
  | expMultiplicativa '%' expUnaria     {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"No se puede realizar la operación RESTO con el tipo de dato %s \n", tipo);}}
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

listaArgumentosOP: /* vacío */
  | listaArgumentos
;


listaArgumentos: argumento
  | listaArgumentos ',' argumento
;

argumento: IDENTIFICADOR {agregar_info(&listaParametros, tipo_variable(listaVariables, $<cadena>1, archivoFinal));}
  | NUM {agregar_info(&listaParametros, "int");}
  | CONS_REAL {agregar_info(&listaParametros, "float");}
  | LIT_CADENA {agregar_info(&listaParametros, "char*");}
;

expPrimaria: IDENTIFICADOR {char* comparar_tipo = tipo_variable(listaVariables, $<cadena>1, archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo[0] == '\0'){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s\n", comparar_tipo, tipo);}}}
  | NUM {if(tipo[0] == '\0'){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s\n", tipo);};}
  | CONS_REAL {if(tipo[0] == '\0'){strcpy(tipo, "float");}else if(!control_tipos(tipo, "float")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un float y un %s\n", tipo);}}
  | LIT_CADENA {if(tipo[0] == '\0'){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s\n", tipo);}}
  | '(' expresion ')'
;



















sentencia: sentExpresion
  | sentCompuesta
  | sentSeleccion 
  | sentIteracion 
  | sentEtiquetada 
  | sentSalto 
;
    /*   {fprintf(archivoFinal,"se encontro una expresion \n");}   */
     /* {fprintf(archivoFinal,"se encontro un sentencia de seleccion \n");} */
     /* {fprintf(archivoFinal,"se encontro un sentencia de iteracion \n");} */
     /* {fprintf(archivoFinal,"se encontro un sentencia etiquetada \n");} */
     /* {fprintf(archivoFinal,"se encontro un sentencia de salto \n");} */


sentCompuesta: '{' listaDeclaracionesOP listaSentenciasOP '}' 
; /* {fprintf(archivoFinal,"se encontro una sentencia compuesta \n");} */ 

listaDeclaraciones: declaracion 
  | listaDeclaraciones declaracion
;

listaDeclaracionesOP: /* vacío */
  | listaDeclaraciones
;


listaSentencias: sentencia
  | listaSentencias sentencia
;

listaSentenciasOP: /* vacío */
  | listaSentencias
;

sentExpresion: expresionOP ';'
;

sentSeleccion: IF '(' expresion ')' sentencia  elseOP
  | SWITCH '(' expresion ')' sentencia    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "SWITCH");}
;
/*   | error {fprintf(archivoFinal,"error en sentencia IF \n");} */

elseOP: /* vacío */   {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "IF");}
  | ELSE sentencia    {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "ELSE IF");}
;

sentIteracion: WHILE '(' expresion ')' sentencia     {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "WHILE");}
  | DO sentencia WHILE '(' expresion ')' ';'         {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "DO");}
  | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia   {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, numeroDeLinea , "FOR");}
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

                         
  fprintf(archivoFinal, "----------------------------------- ERRORES SEMÁNTICOS ----------------\n\nSe encontraron los siguientes errores semánticos:\n\n");



  yyparse();
  yylex();

  
  imprimir_lista_variables(listaVariables, archivoFinal);
  imprimir_validaciones_sintacticas(&listaDeValidacionesSintacticas, archivoFinal);
  imprimir_funciones(listaVariables, archivoFinal);
  imprimir_errores(&listaErroresLexicos, archivoFinal);
  imprimir_errores_sintacticos(&listaErroresSintacticos, archivoFinal);



  fclose(archivoFinal);
  return 0;
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG

}


int control_tipos(char palabra[], char tipo[]) {
  if(!strcmp(palabra, tipo)){
    return 1;
  }
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float") || !strcmp(palabra, "char")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  if((!strcmp(tipo, "int*") || !strcmp(tipo, "float*")) && (!strcmp(palabra, "int*") || !strcmp(palabra, "float*"))){
    return 1;
  }
  if((!strcmp(tipo, "char*") || !strcmp(tipo, "int*") || !strcmp(tipo, "float*")) && (!strcmp(palabra, "void*"))){
    return 1;
  }
  if((!strcmp(palabra, "char*") || !strcmp(palabra, "int*") || !strcmp(palabra, "float*")) && (!strcmp(tipo, "void*"))){
    return 1;
  }
  if((!strcmp(tipo, "const") || !strcmp(tipo, "volatile") || !strcmp(tipo, "typedef") || !strcmp(tipo, "int")) && (!strcmp(palabra, "const") || !strcmp(palabra, "volatile") || !strcmp(palabra, "typedef") || !strcmp(palabra, "int"))){
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

void agregar_info(nodoInfo** listaParametros, char tipo[]){
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
                             
  fprintf(archivoFinal, "\n\n----------------------------------- VARIABLES -------------------------\n\n");
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
  fprintf(archivoFinal, "\n---------------------------------- FUNCIONES --------------------------\n\nSe encontraron las siguientes funciones declaradas:\n\n");
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
  fprintf(archivoFinal, "\n---------------------------------- ERRORES LÉXICOS --------------------\n\nSe encontraron los siguientes errores léxicos:\n\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "%s\n", aux->info);
    (*lista) = aux->sig;
    free(aux->info);
    free(aux);
  }
}

void imprimir_errores_sintacticos(nodoErroresSintacticos** lista, FILE* archivoFinal){
  nodoErroresSintacticos* aux;
  fprintf(archivoFinal, "\n-------------------------------- ERRORES SINTÁCTICOS ------------------\n\nSe encontraron errores sintácticos en las siguientes lineas:");
  fprintf(archivoFinal, "\n\n_____________________________\n");
  fprintf(archivoFinal, "│    ERRORES SINTÁCTICOS    │\n");
  fprintf(archivoFinal, "│___________________________│\n");
  fprintf(archivoFinal, "│      Número de Línea      │\n");
  fprintf(archivoFinal, "│___________________________│\n");
  fprintf(archivoFinal, "│                           │\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "│            %-14d │\n", aux->linea);
    (*lista) = aux->sig;
    free(aux);
  }
  fprintf(archivoFinal, "│___________________________│\n\n");
}

void agregar_error_sintactico(nodoErroresSintacticos** listaParametros, int nroLinea){
  nodoErroresSintacticos* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoErroresSintacticos));
    (*listaParametros)->linea = nroLinea;
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoErroresSintacticos));
  aux->sig->linea = nroLinea;
  aux->sig->sig = NULL;
  return;
}


void agregar_validaciones_sintacticas(nodoValidacionesSintacticas** listaParametros, int nroLinea , char mensaje[]){
  nodoValidacionesSintacticas* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoValidacionesSintacticas));
    strcpy((*listaParametros)->info, mensaje);
    (*listaParametros)->linea = nroLinea;
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoValidacionesSintacticas));
  strcpy(aux->sig->info, mensaje);
  aux->sig->linea = nroLinea;
  aux->sig->sig = NULL;
  return;
}


/*
    fprintf(archivoFinal, "\n\n_______________________________________________________________________\n");
    fprintf(archivoFinal, "|                    Lista de Palabras Reservadas                     |\n");
    fprintf(archivoFinal, "|_____________________________________________________________________|\n");
    fprintf(archivoFinal, "|             Lexema     |                 Categoria                  |\n");
    fprintf(archivoFinal, "|________________________|____________________________________________|\n");

    imprimirCola(PalabrasReservadas, archivoFinal, P_RESERVADA);
    fprintf(archivoFinal, "|________________________|____________________________________________|\n\n");*/

void imprimir_validaciones_sintacticas(nodoValidacionesSintacticas** lista, FILE* archivoFinal){
  nodoValidacionesSintacticas* aux;
   fprintf(archivoFinal, "\n---------------------------------- SENTENCIAS -------------------------\n\n");
  fprintf(archivoFinal, "Se encontraron las siguientes sentencias:");
  fprintf(archivoFinal, "\n\n_______________________________________________________________________\n");
  fprintf(archivoFinal, "│                             SENTENCIAS                              │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│               Tipo                  │       Número de Línea         │\n");
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n");
  fprintf(archivoFinal, "│                                     │                               │\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "│ %-34s  │              %-16d │\n", aux->info, aux->linea);
    (*lista) = aux->sig;
    free(aux);
  }
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n\n");
}



