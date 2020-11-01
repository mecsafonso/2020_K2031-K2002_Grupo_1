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

line: '\n'
  | sentencia '\n'
  | declaracion '\n'
;






declaracion: especificadoresDeclaracion listaDeclaradoresOP ';' {printf("se encontro una declaracion \n");}
  | especificadoresDeclaracion listaDeclaradoresOP sentCompuesta {printf("se encontró una desarrollo de función")}
;

/* En la segunda linea se va a el desarrollo de una funcion, sin embargo esta puede escribirse como int asd(a,b){} debido a listaIdentificadoresOP, */
/* como el compilador no da error sino un warning, se decidió dejarlo así */

listaDeclaradoresOP: {printf("se fue al vacio")}
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
  | listaDeclaradores ',' declarador {printf("se encontro mas de una declaracion \n");}
;

declarador: decla
  | decla OPER_ASIGNACION inicializador {printf("se encontro una asignacion \n");}
;

inicializador: expAsignacion 
  | '{' listaInicializadores '}'
  | '{' listaInicializadores ',' '}'
;

listaInicializadores: inicializador
  | listaInicializadores ',' inicializador
;

especificadorClaseAlmacenamiento: ESPECIFICADOR_ALMACENAMIENTO
;

especificadorTipo: ESPECIFICADOR_TIPO {printf("se encontro el tipo de dato %s \n", $<cadena>1);}
  | especificadorStructOUnion
  | especificadorEnum
;



calificadorTipo: CONST
  | VOLATILE
;

especificadorStructOUnion: structOUnion identificadorOP '{' listaDeclaracionesStruct '}'
  | structOUnion IDENTIFICADOR
;

identificadorOP: 
  | IDENTIFICADOR
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

puntero: '*' listaCalificadoresTiposOP
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

declaradorDirecto: IDENTIFICADOR {printf("se encontro declaradorDirecto %s \n", $<cadena>1);}
  | '(' decla ')'
  | declaradorDirecto '[' expConstanteOP ']'
  | declaradorDirecto '(' listaTiposParametros ')' {printf("se encontró una firma de función")}
  | declaradorDirecto '(' listaIdentificadoresOP ')'
	| error {flag_error=1;printf("error xd \n");}
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

declaracionParametro: especificadoresDeclaracion decla
  | especificadoresDeclaracion declaradorAbstractoOP
;

listaIdentificadores: IDENTIFICADOR
  | listaIdentificadores ',' IDENTIFICADOR
;

listaIdentificadoresOP: 
  | listaIdentificadores
;

especificadorEnum: ENUM identificadorOP '{' listaEnumeradores '}'
  | ENUM IDENTIFICADOR
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










expresion: expAsignacion
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
  | expOr OPER_OR expAnd    {printf("se encontro una expresion OR \n";}
;

expAnd: expIgualdad
  | expAnd OPER_AND expIgualdad   {printf("se encontro una expresion AND \n";}
;

expIgualdad: expRelacional
  | expIgualdad OPER_IGUALDAD expRelacional   {printf("se encontro una expresion de IGUALDAD \n";}
  | expIgualdad OPER_DIFERENCIA expRelacional   {printf("se encontro una expresion de DIFERENCIA \n";}
;

expRelacional: expAditiva
  | expRelacional OPER_RELACIONAL expAditiva    {printf("se encontro una expresion RELACIONAL \n";}
;

expAditiva: expMultiplicativa
  | expAditiva '+' expMultiplicativa    {printf("se encontro una expresion de SUMA \n";}
  | expAditiva '-' expMultiplicativa    {printf("se encontro una expresion de RESTA \n";}
;

expMultiplicativa: expUnaria
  | expMultiplicativa '*' expUnaria     {printf("se encontro una expresion de MULTIPLICACION \n";}
  | expMultiplicativa '/' expUnaria     {printf("se encontro una expresion de DIVISION \n";}
  | expMultiplicativa '%' expUnaria     {printf("se encontro una expresion de RESTO \n";}
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

expPrimaria: IDENTIFICADOR {printf("se encontro el identificador %s \n", $<cadena>1);}
  | NUM {printf("se encontro el valor %i \n", $<entero>1);}
  | CONS_REAL
  | LIT_CADENA
  | '(' expresion ')'
  | error {flag_error=1;printf("Expresion unaria no valida \n");}
;



















sentencia: sentCompuesta
  | sentExpresion {printf("se encontro una expresion \n";}
  | sentSeleccion {printf("se encontro un sentencia de seleccion \n";}
  | sentIteracion {printf("se encontro un sentencia de iteracion \n";}
  | sentEtiquetada {printf("se encontro un sentencia etiquetada \n";}
  | sentSalto {printf("se encontro un sentencia de salto \n";}
;

sentCompuesta: '{' listaDeclaracionesOP listaSentenciasOP '}' {printf("se encontro una sentencia compuesta \n");}
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

  //yydebug = 1; --> Utilizar en caso de MODO DEBUG
  yyparse ();
}
