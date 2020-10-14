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
%token <cadena> IDENTIFICADOR
%token <cadena> TIPO_DATO
%token <entero> error
%token <cadena> OPERADOR
%token <cadena> PUNTUACION
%token <cadena> OPERASIGNACION
%token <cadena> LIT_CADENA
%token <cadena> CARACTER


%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line:     '\n'
    | declaVarSimples '\n'
;

/* Declaraciones y definiciones de variable simples: (Pag 63) */
;

declaVarSimples: TIPO_DATO listaVarSimples ';' {printf("se declaro una variable de tipo %s", $<cadena>1)}
               | error caracterDeCorte
;

listaVarSimples: unaVarSimple
	| listaVarSimples ',' unaVarSimple
;

unaVarSimple: variable inicial
	| variable
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

%%

int main ()
{

  //yydebug = 1; --> Utilizar en caso de MODO DEBUG
  yyparse ();
}