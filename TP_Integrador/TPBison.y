%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "TPIntegrador.h"

#include <stdlib.h>


extern int yylineno;

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
nodoInfo* listaParametros = NULL;
nodoErroresSintacticos* listaErroresSintacticos = NULL;
nodoError* listaDeValidacionesSintacticas = NULL;


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
  | decla OPER_ASIGNACION inicializador  {agregar_validaciones_sintacticas(&listaDeValidacionesSintacticas, yylineno , "ASIGNACION");}
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
/* 	| error {flag_error=1;fprintf(archivoFinal,"   ♦ Error con identificador %s \n", $<cadena>1);} */

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
  | expMultiplicativa '*' expUnaria     {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"   ♦ No se puede realizar la operación MULTIPLICACION con el tipo de dato %s \n", tipo);}}
  | expMultiplicativa '/' expUnaria     {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"   ♦ No se puede realizar la operación DIVISION con el tipo de dato %s \n", tipo);}}
  | expMultiplicativa '%' expUnaria     {if(!control_tipos(tipo, "int") && !control_tipos(tipo, "int*")){fprintf(archivoFinal,"   ♦ No se puede realizar la operación RESTO con el tipo de dato %s \n", tipo);}}
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

expPrimaria: IDENTIFICADOR {char* comparar_tipo = tipo_variable(listaVariables, $<cadena>1, archivoFinal);if(strcmp(comparar_tipo, "error")){if(tipo[0] == '\0'){strcpy(tipo, comparar_tipo);}else if(!control_tipos(tipo, comparar_tipo)){fprintf(archivoFinal, "   ♦ No se puede realizar la operacion requerida entre un %s y un %s\n", comparar_tipo, tipo);}}}
  | NUM {if(tipo[0] == '\0'){strcpy(tipo, "int");}else if(!control_tipos(tipo, "int")){fprintf(archivoFinal, "   ♦ No se puede realizar la operacion requerida entre un int y un %s\n", tipo);};}
  | CONS_REAL {if(tipo[0] == '\0'){strcpy(tipo, "float");}else if(!control_tipos(tipo, "float")){fprintf(archivoFinal, "   ♦ No se puede realizar la operacion requerida entre un float y un %s\n", tipo);}}
  | LIT_CADENA {if(tipo[0] == '\0'){strcpy(tipo, "char*");}else if(!control_tipos(tipo, "char*")){fprintf(archivoFinal, "   ♦ No se puede realizar la operacion requerida entre un char* y un %s\n", tipo);}}
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

                         
  fprintf(archivoFinal, "------------------------- ERRORES SEMÁNTICOS --------------------------\n\n * Se encontraron los siguientes errores semánticos:\n\n");



  yyparse();
  yylex();

  imprimir_errores(&listaErroresLexicos, archivoFinal);
  imprimir_errores_sintacticos(&listaErroresSintacticos, archivoFinal);
  imprimir_validaciones_sintacticas(&listaDeValidacionesSintacticas, archivoFinal);
  imprimir_lista_variables(listaVariables, archivoFinal);
  imprimir_funciones(listaVariables, archivoFinal);




  fclose(archivoFinal);
  return 0;
  //yydebug = 1; --> Utilizar en caso de MODO DEBUG

}
