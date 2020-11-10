%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "TP4.h"

#define YYDEBUG 1
extern FILE *yyin;
extern FILE *yyout;

int flag_error=0;
int contador=0;
char* tipo;
char* identificador;
int modo_funcion = 0;
int contador_parametros = 0;

FILE* archivoFinal;

nodoVariables* listaVariables = NULL;
nodoFuncion* listaFunciones = NULL;
nodoError* listaErroresLexicos = NULL;
nodoVariable* listaParametros = NULL;


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
%token <cadena> ERROR_LEXICO


%% 

input:    
  | input line
;

line: '\n'  {fprintf(archivoFinal,"\n--------------------------------------- \n \n");}
  | sentencia '\n'    {fprintf(archivoFinal,"\n-----------------SENTENCIA---------------- \n \n");}
  | declaracion '\n'  {fprintf(archivoFinal,"\n-----------------DECLARACION---------------- \n \n");}
;




declaracion: especificadoresDeclaracion listaDeclaradoresOP ';' {fprintf(archivoFinal,"se encontro una declaracion \n");}
  | especificadoresDeclaracion listaDeclaradoresOP sentCompuesta {fprintf(archivoFinal,"se encontró una desarrollo de función")}
;

/* En la segunda linea se va a el desarrollo de una funcion, sin embargo esta puede escribirse como int asd(a,b){} debido a listaIdentificadoresOP, */
/* como el compilador no da error sino un warning, se decidió dejarlo así */

listaDeclaradoresOP: {tipo = NULL}
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

especificadorClaseAlmacenamiento: ESPECIFICADOR_ALMACENAMIENTO {if(tipo == NULL){strcpy(tipo, $<cadena>1)}}
;

especificadorTipo: ESPECIFICADOR_TIPO {strcpy(tipo, $<cadena>1) ; fprintf(archivoFinal, "se encontro el tipo de dato %s \n", $<cadena>1);}
  | especificadorStructOUnion 
  | especificadorEnum 
;



calificadorTipo: CONST {if(tipo == NULL){strcpy(tipo, $<cadena>1)}}
  | VOLATILE {if(tipo == NULL){strcpy(tipo, $<cadena>1)}}
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

declaradorDirecto: IDENTIFICADOR {gestionar_identificador(listaFunciones, listaVariables, $<cadena>1, tipo, modo_funcion, listaParametros, archivoFinal);}
  | '(' decla ')'
  | IDENTIFICADOR '[' expConstanteOP ']'
  | IDENTIFICADOR '(' listaTiposParametros ')'
  | IDENTIFICADOR '(' listaIdentificadoresOP ')'
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

declaracionParametro: especificadoresDeclaracion decla {contador_parametros++;}
  | especificadoresDeclaracion declaradorAbstractoOP
;

listaIdentificadores: IDENTIFICADOR {agregar_variable(listaParametros, $<cadena>1, "int");}
  | listaIdentificadores ',' IDENTIFICADOR {agregar_variable(listaParametros, $<cadena>2, "int");}
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

nombreTipo: listaCalificadores declaradorAbstractoOP
;

declaradorAbstracto: puntero 
  | punteroOP declaradorAbstractoDirecto
;

declaradorAbstractoOP: 
  | declaradorAbstracto
;

declaradorAbstractoDirecto: '(' declaradorAbstracto ')'
  | declaradorAbstractoDirectoOP '[' expConstanteOP ']'
  | declaradorAbstractoDirectoOP '(' listaTiposParametrosOP ')'
;

declaradorAbstractoDirectoOP: 
  | declaradorAbstractoDirecto
;










expresion: expAsignacion {tipo = NULL;}
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
  | expPostfijo '(' listaArgumentosOP ')'
;

listaArgumentosOP:
  | listaArgumentos
;

listaArgumentos: expAsignacion
  | listaArgumentos ',' expAsignacion
;

expPrimaria: IDENTIFICADOR {char* comparar_tipo = tipo_variable(listaVariables, &<cadena>1, archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo == NULL){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un %s y un %s", comparar_tipo, $<cadena>1);}}}
  | NUM {if(tipo == NULL){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un int y un %s", $<cadena>1);}}
  | CONS_REAL {if(tipo == NULL){strcpy(tipo, "char");}else if(!control_tipos(tipo, "char")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char y un %s", $<cadena>1);}}
  | LIT_CADENA {if(tipo == NULL){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "No se puede realizar la operacion requerida entre un char* y un %s", $<cadena>1);}}
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
  imprimir_funciones(listaFunciones, archivoFinal);
  imprimir_errores(listaErroresLexicos, archivoFinal);

  fclose(archivoFinal);
  return 0;
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG

}

