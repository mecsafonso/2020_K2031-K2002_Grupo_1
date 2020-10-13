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
function* funcionAnterior = funcionAcutal;
function* variablesGlobales = listaFunciones;
var* variableAComparar;

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


void gestionarIdentificador(char const* nombre, char const* tipo, function* funcionActual);

%% /* A continuacion las reglas gramaticales y las acciones */

input: /* vacio */
     | input line
;

line: '\n'
    | sentenciaDeclaracion '\n'
    | sentenciaExprecion '\n'
    | sentenciaFuncion '\n'
;

sentenciaDeclaracion: TIPO_DATO {strcpy(tipo, $<cadena>1);} declaraciones
						        | error ';' {if(flag_error==0){putvar("", funcionAcutal->ts_errores, "Tipo no reconocido")} flag_error = 0;}
;

declaraciones: listaIdentificadores ';'
             | identificadorFuncion
;

listaIdentificadores:	identificadorA ',' listaIdentificadores
                    | identificadorA
            
;

identificadorA:	IDENTIFICADOR '=' expresion {strcpy(id, $<cadena>1);}
						  | IDENTIFICADOR {strcpy(id, $<cadena>1);gestionarIdentificador(id, tipo, funcionAcutal);}
              | error {if(flag_error==0){printf("Falta identificador \n");flag_error=1;};}
;

identificadorFuncion: IDENTIFICADOR {funcionAcutal = gestionarFuncion($<cadena>1, tipo, listaFunciones)} '(' sentenciaDeclaracionFuncion ')' codigoFuncion {funcionAcutal = funcionAnterior}
;

sentenciaDeclaracionFuncion: /* vacio */
                           |soloTipo
                           | tipoEIdentificador
;

codigoFuncion: '{'input retorno'}'
             | ';'
;

retorno: /* vacio */ (if(!compatibleA("void", funcionAcutal->return_type)) funcionAcutal->errorRetorno = true;)
       |RETURN IDENTIFICADOR {gestionarRetorno(funcionAcutal, $<cadena>2)} ';'
       | RETURN ';' (if(!compatibleA("void", funcionAcutal->return_type)) funcionAcutal->errorRetorno = true;)
;

soloTipo: TIPO_DATO 
        | TIPO_DATO ',' soloTipo
        | error (putvar("", funcionAcutal->ts_errores, "Tipo no reconocido"))
;

tipoEIdentificador: TIPO_DATO IDENTIFICADOR {gestionarIdentificador($<cadena>2, $<cadena>1, funcionAcutal);}
                  | TIPO_DATO IDENTIFICADOR {gestionarIdentificador($<cadena>2, $<cadena>1, funcionAcutal);}',' tipoEIdentificador
                  | error (putvar("", funcionAcutal->ts_errores, "Tipo no reconocido"))
;

expresion: DECIMAL {if(compatibleA("int", tipo)){gestionarIdentificador(id, tipo, funcionAcutal)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
         | REAL {if(compatibleA("float", tipo)){gestionarIdentificador(id, tipo, funcionAcutal)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
			   | CCARACTER {if(compatibleA("char", tipo)){gestionarIdentificador(id, tipo, funcionAcutal)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
         | LIT_CADENA {if(compatibleA("char*", tipo)){gestionarIdentificador(id, tipo, funcionAcutal)}else{putvar(id, funcionAcutal->ts_errores, "Error de tipos");}}
         | error {flag_error=1;printf("Valor no reconocido para asignar \n");}
;

sentenciaExprecion: IDENTIFICADOR {variableAComparar = gestionarIdentificador($<cadena>1, "", funcionActual); if(variableAComparar!= NULL)strcpy(tipo, variableAComparar->type);} '=' listaExpresion ';'
;

listaExpresion: elementoExpresion
              | elementoExpresion OPERADOR listaExpresion
;

elementoExpresion: IDENTIFICADOR {variableAComparar = gestionarIdentificador($<cadena>1, "", funcionActual); if(variableAComparar!= NULL && !compatibleA(variableAComparar->type, tipo)) putvar($<cadena>1, funcionAcutal->ts_errores, "Problema de tipos");}
                 | espresion
                 | error {if(!flag_error) {putvar("", funcionAcutal->ts_errores, "Caracter no valido"); flag_error = 1;}}
;



%%

int main ()
{
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG
  yyparse ();
}

var* gestionarIdentificador(char const* nombre, char const* tipo, function* funcionActual){
  var* variable = getvar(nombre, funcionAcutal->ts_var)
  if(variable==NULL){
    if (tipo[0]=='\0'){
      variable = putvar(nombre, funcionAcutal->ts_errores, "Variable no declarada");
    } else {
      variable = putvar(nombre, funcionAcutal->ts_var, tipo);
    }
  } else if (variable!= NULL){
    variable = putvar(nombre, funcionAcutal->ts_errores, "Doble declaracion");
  }
  return variable;
}

void gestionarRetorno(function* funcionActual, char const* identificador){
  var* variable = getvar(nombre, funcionAcutal->ts_var)
  if(variable==NULL || strcmp(variable->type, funcionActual->return_type)){
    funcionActual->errorRetorno = true
  } 
}

function* gestionarFuncion (char const* nombre, char const* tipo, function* listaFunciones){
  function* funcion = getfunc(nombre, listaFunciones);
  if(funcion == NULL){
    if (tipo == '\0'){
      putvar(nombre, variablesGlobales->ts_errores, "Funcion no declarada");
    } else {
      function = putfunc(nombre, listaFunciones, tipo)
    }
  } else if(tipo != '\0' && !compatibleA(tipo, funcion->return_type)){
    putvar(nombre, variablesGlobales->ts_errores, "Funcion: error de tipos");
  }
  return funcion;
}