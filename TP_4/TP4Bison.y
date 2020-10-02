%{
#include <math.h> // pow
#include <stdio.h>
#include <string.h> // strcpy, strcmp
#include <ctype.h> // toupper y isdigit
#include <stdlib.h> // atoi, atof
#include "TP4.h"
#define YYDEBUG 1
int flag_error=0;
extern FILE *yyin;
extern FILE *yyout;

int yylex();
void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}

function* listaFunciones = NULL;
putfunc(variablesGlobales, listaFunciones, "Variables Globales");
function* funcionAcutal = listaFunciones;


char tipo[30];
char id[50];

%}

%union {
char cadena[30];
int num;
float real;
char caracter;
}

%token <num> DECIMAL
%token <real> REAL
%token <cadena> IDENTIFICADOR
%token <cadena> TIPO_DATO
%token <cadena> LIT_CADENA
%token <cadena> ESTRUCTURA_DE_CONTROL
%token <cadena> PALABRA_RESERVADA
%token <caracter> CCARACTER
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
%token <num> ERROR
%token <cadena> COMENTARIO


void gestionarIdentificador(char const* nombre, char const* tipo, var* listaVariables);

%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line: '\n'
    | sentenciaDeclaracion '\n'
    |  
;

sentenciaDeclaracion: TIPO_DATO {strcpy(tipo=$<cadena>1);} declaraciones
						        | error caracterDeCorte {if(flag_error==0){putvar("", funcionAcutal->ts_errores, "Tipo no reconocido")} flag_error = 0;}
;

declaraciones: listaIdentificadores ';'
             | identificadorFuncion '{'input retorno'}'
;

listaIdentificadores:	identificadorA ',' listaIdentificadores
                    | identificadorA
                    | identificadorFuncion
            
;

identificadorA:	IDENTIFICADOR '=' expresion {strcpy(id=$<cadena>1);}
						  | IDENTIFICADOR {strcpy(id=$<cadena>1);gestionarIdentificador(id, tipo, funcionAcutal->ts_var);}
              | error {if(flag_error==0){printf("Falta identificador \n");flag_error=1;};}
;

identificadorFuncion: IDENTIFICADOR '(' sentenciaDeclaracionFuncion ')' {funcionAcutal = putfunc($<cadena>1, listaFunciones, tipo)}
;

sentenciaDeclaracionFuncion: soloTipo
                           | tipoEIdentificador
                           | %empty
;

soloTipo: TIPO_DATO 
        | TIPO_DATO ',' soloTipo
        | error (putvar("", listaErrores, "Tipo no reconocido"))
;

tipoEIdentificador: TIPO_DATO IDENTIFICADOR {gestionarIdentificador($<cadena>2, $<cadena>1, funcionAcutal->ts_var);}
                  | TIPO_DATO IDENTIFICADOR {gestionarIdentificador($<cadena>2, $<cadena>1, funcionAcutal->ts_var);}',' tipoEIdentificador
                  | error (putvar("", listaErrores, "Tipo no reconocido"))


expresion: DECIMAL {if(compatibleA("int", tipo)){gestionarIdentificador(id, tipo, funcionAcutal->ts_var)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
         | REAL {if(compatibleA("float", tipo)){gestionarIdentificador(id, tipo, funcionAcutal->ts_var)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
			   | CCARACTER {if(compatibleA("char", tipo)){gestionarIdentificador(id, tipo, funcionAcutal->ts_var)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
         | LIT_CADENA {if(compatibleA("char*", tipo)){gestionarIdentificador(id, tipo, funcionAcutal->ts_var)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
         | error {flag_error=1;printf("Valor no reconocido para asignar \n");}
;

caracterDeCorte:	';' | '\n'
;

%%

int main ()
{
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG
  yyparse ();
}

void gestionarIdentificador(char const* nombre, char const* tipo, var* listaVariables){
  var* variable;
  if(tipo[0]=='\0'){
    if (getvar(nombre, listaVariables)==0){
      variable = putvar(nombre, listaErrores, "Variable no declarada");
    } else {
      variable = getvar(nombre, listaVariables);
    }
  } else if (getvar(nombre, listaVariables)!=0){
    variable = putvar(nombre, listaErrores, "Doble declaracion");
  } else{
    variable = putvar(nombre, listaVariables, tipo);
  } 
}