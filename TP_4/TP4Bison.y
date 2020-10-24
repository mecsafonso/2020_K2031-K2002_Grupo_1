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
%token <cadena> TIPO_DATO
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
%token <cadena> OPER_ASIGNACION
%token <cadena> OPER_OR
%token <cadena> OPER_AND
%token <cadena> OPER_IGUALDAD
%token <cadena> OPER_DIFERENCIA
%token <cadena> OPER_RELACIONAL
%token <cadena> OPER_INC_DEC
%token <cadena> OPER_NEGACION
%token <cadena> OPER_DIRECCION


%% 

input:    
  | input line
;

line: '\n'
  | sentencia '\n'
;



expresion: expAsignacion
;

expresionOP: 
  | expresion
;

expAsignacion: expCondicional
  | expUnaria operAsignacion expAsignacion
;

operAsignacion: OPER_ASIGNACION
;

expCondicional: expOr 
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

nombreTipo: TIPO_DATO
;

operUnario: OPER_DIRECCION
  |'*'
  |'-'
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

expPrimaria: IDENTIFICADOR
  | NUM {printf("se encontro el valor %i \n", $<entero>1);}
  | CONS_REAL
  | LIT_CADENA
  | '(' expresion ')'
  | error {flag_error=1;printf("constante no valida \n");}
;








declaracion: declaVarSimples
  | declaStruct
;

declaStruct:  STRUCT IDENTIFICADOR '{' TIPO_DATO listaDeVariables ';' soloDeclarar '}' IDENTIFICADOR ';' {printf("Se encontró un struct \n");}
  | STRUCT IDENTIFICADOR '{' TIPO_DATO listaDeVariables ';' soloDeclarar '}' ';' {printf("Se encontro un struct \n");}
;


soloDeclarar: 
  | TIPO_DATO listaDeVariables ';' soloDeclarar
;

declaVarSimples: TIPO_DATO  {printf("se declaro una variable de tipo %s \n", $<cadena>1);}  listaVarSimples ';'
  | error caracterDeCorte {printf("Falta tipo de dato \n");}
;

listaVarSimples: unaVarSimple
	| listaVarSimples ',' unaVarSimple
;

unaVarSimple: variable inicial
	| variable
  | variable '[' NUM ']'
;

listaDeVariables: variable
  | variable ',' variable
;

variable: IDENTIFICADOR 
;

inicial: OPER_ASIGNACION CONSTANTE 
;

CONSTANTE: NUM
  | LIT_CADENA
  | CARACTER
  | error {flag_error=1;printf("constante no valida \n");}
;

caracterDeCorte:	';' | '\n'
;
























sentencia: sentCompuesta
  | sentExpresion
  | sentSeleccion 
  | sentIteracion
  | sentEtiquetada
  | sentSalto
  | declaracion
;

sentCompuesta: '{' listaSentencias '}' {printf("se encontro una sentencia compuesta \n");}
;

listaSentencias: sentencia
  | listaSentencias sentencia
;

sentExpresion: expresionOP
;

sentSeleccion: IF '(' expresion ')' sentencia  {printf("se encontro un if \n");}
  | IF '(' expresion ')' sentencia ELSE sentencia  {printf("se encontro un if con un else \n");}
  | SWITCH '(' expresion ')' sentencia {printf("se encontro un switch \n");}
;

sentIteracion: WHILE '(' expresion ')' sentencia
  | DO sentencia WHILE '(' expresion ')' ';'
  | FOR '(' expresionOP ';' expresionOP ';' expresionOP ')' sentencia
;

sentSalto: RETURN expresionOP ';'
  | CONTINUE ';'
  | BREAK ';'
  | GOTO IDENTIFICADOR ';'
;

sentExpresion: expresionOP ';' 
;

sentEtiquetada: CASE  expresion ':' sentencia
  | DEFAULT ':' sentencia
  | IDENTIFICADOR ':' sentencia
;




















%%

int main ()
{

  //yydebug = 1; --> Utilizar en caso de MODO DEBUG
  yyparse ();
}
