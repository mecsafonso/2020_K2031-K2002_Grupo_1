/* Sentencias (todos los tipos: compuesta, If, While, Salto, For, Expresión, etc) */
/* Declaraciones de variables (puede agregar variables tipo puntero y tipo arreglo) de forma correcta almacenando en TS. */
/* Declaraciones de funciones de forma correcta almacenando en TS.*/
/* Expresiones (que están incluidas dentro de las sentencias). */

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define YYDEBUG 1

int flag_error=0;
int contador=0;
char* tipo;

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
%token <cadena> ARRAY
%token <cadena> TIPO_DATO
%token <entero> error
%token <cadena> OPERADOR
%token <cadena> PUNTUACION
%token <cadena> OPERASIGNACION
%token <cadena> LIT_CADENA
%token <cadena> CARACTER
%token <cadena> FOR
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> SWITCH
%token <cadena> BREAK
%token <cadena> CASE
%token <cadena> DEFAULT
%token <cadena> RETURN
%token <cadena> IF
%token <cadena> ELSE


%% /* A continuación las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line:     '\n'
    | declaVarSimples '\n'
    | sentencia
;






/* EXPRESIONES (Pag 59) */

expresion: expAsignacion
;

expresionOP: 
  | expresion
;

expAsignacion: expCondicional
  | expUnaria operAsignacion expAsignacion
;

/* operAsignacion: '=' */
/*  | "+=" ; */

operAsignacion: OPER_ASIGNACION
;

expCondicional: expOr 
/*  | expOr ? expresion : expCondicional; */
;

expOr: expAnd
  | expOr OPER_OR expAnd    
;

expAnd: expIgualdad
  | expAnd OPER_AND expIgualdad
;

expIgualdad: expRelacional
  | expIgualdad OPER_IGUALDAD expRelacional
  | expIgualdad OPER_DIFERENCIA expRelacional
;

expRelacional: expAditiva
  | expRelacional OPER_RELACIONAL expAditiva

;

expAditiva: expMultiplicativa
  | expAditiva '+' expMultiplicativa
  | expAditiva '-' expMultiplicativa
;

expMultiplicativa: expUnaria
  | expMultiplicativa '*' expUnaria
  | expMultiplicativa '/' expUnaria
;

expUnaria: expPostfijo
  | OPER_INC_DEC expUnaria
  | operUnario expUnaria
  | SIZEOF '(' nombreTipo ')'
;

operUnario: OPER_DIRECCION
  |'*'
  |'-'
  |OPER_NEGACION
;

expPostfijo: expPrimaria
  | expPostfijo '[' expresion ']'
  | expPostijo '(' listaArgumentosOP ')'
;

listaArgumentosOP:
  | listaArgumentos
;

listaArgumentos: expAsignacion
  | listaArgumentos ',' expAsignacion
;

expPrimaria: IDENTIFICADOR,
| NUM
| LIT_CADENA
| '(' expresion ')'
;







/* Declaraciones y definiciones de variable simples: (Pag 63) */



declaVarSimples: TIPO_DATO listaVarSimples ';' {printf("se declaro una variable de tipo %s", $<cadena>1)}
  | error caracterDeCorte
;

listaVarSimples: unaVarSimple
	| listaVarSimples ',' unaVarSimple
;

unaVarSimple: variable inicial
	| variable
  | variable '[' NUM ']'
;

variable: IDENTIFICADOR ;
inicial: OPERASIGNACION CONSTANTE ;

CONSTANTE: NUM
  | LIT_CADENA
  | CARACTER
  | error {flag_error=1;printf("constante no valida \n");}
;
caracterDeCorte:	';' | '\n'
;








/*  SENTENCIAS (Pag 64) */

sentencia: sentCompuesta
  | sentExpresion
  | sentSeleccion
  | sentIteracion
  | sentSalto
;

// bloque de código
sentCompuesta: '{' listaDeclaracionesOP listaSentenciasOP '}'
;

listaDeclaracionesOP: 
  | listaDeclaraciones
;

listaDeclaraciones: declaVarSimples
  | listaDeclaraciones declaVarSimples
;

listaSentenciasOP:
  | listaSentencias
;

listaSentencias: sentencia
  | listaSentencias sentencia
;

sentExpresion: expresionOP
;

sentSeleccion: IF '(' expresion ')' sentencia
  | IF '(' expresion ')' sentencia ELSE sentencia
  | SWITCH '(' expresion ')' sentencia
;

sentIteracion: WHILE '(' expresion ')' sentencia
  | DO sentencia WHILE '(' expresion ')' ';'
  | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia
;

sentSalto: RETURN expresionOP ';'
;


sentExpresion: expresionOP ';' 
;







%%

int main ()
{

  //yydebug = 1; --> Utilizar en caso de MODO DEBUG
  yyparse ();
}