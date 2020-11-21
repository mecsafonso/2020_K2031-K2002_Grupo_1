%option noyywrap

%{
#include "TP4Bison.tab.h"

// Definicion de las librerías que incluímos
#include <stdio.h>
#include <string.h> // strcpy, strcmp
#include <ctype.h>  // toupper y isdigi
#include <math.h>   // pow
#include <stdlib.h> // atoi, atof

#define BASE8 8
#define BASE16 16

int caracterHexadecimalADecimal(char);
int convertirAdecimal(char*, int, int);

/* FILE* archivoFinal;*/

struct infoCola{
    char nombre[101];    /* asumimos un tamaño para el literal cadena y de los comentarios de 100 caracteres + '\0'= 101 */
    int cantidad;
    char categoria[32];
} ;

typedef struct nodoCola{
    struct infoCola info;
    struct nodoCola* sgte;
} NodoCola;

struct cola {
    NodoCola* primero;
	NodoCola* ultimo;
} typedef tipoCola;

tipoCola* NoReconocidos;

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
IDENTIFICADOR ({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)*
CONDICION (<|\")
TIPO_DATO char|double|float|int|long|short|signed|unsigned|void
ESPECIFICADOR_ALMACENAMIENTO typedef|static|auto|register|extern
OPERADOR [\+\-\*\/\%]|\+\+|\-\-

%% 

[1-9]{DIGITO_DECIMAL}*  {yylval.entero = atoi(yytext); return NUM;}
0{DIGITO_OCTAL}* {yylval.entero = convertirAdecimal(yytext, BASE8, yyleng); return NUM;}
0[xX]{DIGITO_HEXADECIMAL}+ {yylval.entero = convertirAdecimal(yytext, BASE16, yyleng); return NUM;}

({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+|{DIGITO_DECIMAL}+\.|{DIGITO_DECIMAL}+)([eE][\+\-]?{DIGITO_DECIMAL}+)? {yylval.real = atof(yytext); return CONS_REAL;}

"'"."'" {return CARACTER;}            
","     {return ',';}
"."     {return '.';}
"="|"+="    {strcpy(yylval.cadena,yytext); return OPER_ASIGNACION;}
";"     {return ';';}
":"     {return ':';}
\{      {return '{';}
\}      {return '}';}
"("     {return '(';}
")"     {return ')';}
"["     {return '[';}
"]"     {return ']';}
"||"    {return OPER_OR;}
"&&"    {return OPER_AND;}
"=="    {return OPER_IGUALDAD;}
"!="    {return OPER_DIFERENCIA;}
"<="|">="|<|>    {return OPER_RELACIONAL;}
"++"|"--"   {return OPER_INC_DEC;}
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
"%"     {return '%';}
"!"     {return OPER_NEGACION;}
"&"     {return OPER_DIRECCION;}
\n	{return '\n';}


\"(\\.|[^(\n|\\")])*\" {strcpy(yylval.cadena,yytext); return LIT_CADENA;} 

"for"                           {strcpy(yylval.cadena,yytext); return FOR;}
"while"                         {strcpy(yylval.cadena,yytext); return WHILE;}
"do"                            {strcpy(yylval.cadena,yytext); return DO;}
"switch"                        {strcpy(yylval.cadena,yytext); return SWITCH;}
"break"                         {strcpy(yylval.cadena,yytext); return BREAK;}
"case"                          {strcpy(yylval.cadena,yytext); return CASE;}
"default"                       {strcpy(yylval.cadena,yytext); return DEFAULT;}
"return"                        {strcpy(yylval.cadena,yytext); return RETURN;}
"if"                            {strcpy(yylval.cadena,yytext); return IF;}
"else"                          {strcpy(yylval.cadena,yytext); return ELSE;}
"sizeof"                        {strcpy(yylval.cadena,yytext); return SIZEOF;}
"continue"                      {strcpy(yylval.cadena,yytext); return CONTINUE;}
"goto"                          {strcpy(yylval.cadena,yytext); return GOTO;}
"struct"                        {strcpy(yylval.cadena,yytext); return STRUCT;}
"union"                         {strcpy(yylval.cadena,yytext); return UNION;}
"const"                         {strcpy(yylval.cadena,yytext); return CONST;}
"volatile"                      {strcpy(yylval.cadena,yytext); return VOLATILE;}
"enum"                          {strcpy(yylval.cadena,yytext); return ENUM;}
{TIPO_DATO}                     {strcpy(yylval.cadena,yytext); return ESPECIFICADOR_TIPO;}
{ESPECIFICADOR_ALMACENAMIENTO}  {strcpy(yylval.cadena,yytext); return ESPECIFICADOR_ALMACENAMIENTO;}

{IDENTIFICADOR}                 {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;} 



%%

/* int main() {
 *
 *    yyin = fopen("entrada.txt", "r");
 *    yyout = fopen("salida.txt", "w");
 *    archivoFinal = fopen("Informe.txt", "w");
 *
 *    yylex();
 *    
 *    fclose(archivoFinal);
 *    return 0;
 * } 
 */
int caracterHexadecimalADecimal(char caracter) {
  if (isdigit(caracter))
    return caracter - '0';
  return 10 + (toupper(caracter) - 'A');
}

int convertirAdecimal(char* numeroAconvertir, int Base, int longitud) {
    int numeroDecimal = 0, potencia = 0;
    int valorActual;

    if(numeroAconvertir == "0")
        return numeroDecimal = 0;
    else {
        switch(Base){
            case BASE8:
                for(int i = longitud - 1; i >= 1; i-- ){
                    valorActual = numeroAconvertir[i] - '0';
                    numeroDecimal += valorActual * pow(Base,potencia);
                    potencia++;
                }   
                break;
            case BASE16:
                for(int i = longitud - 1; i >= 2; i-- ){
                    valorActual = caracterHexadecimalADecimal(numeroAconvertir[i]);
                    numeroDecimal += valorActual * pow(Base,potencia);
                    potencia++;
                }
                break;
        }
        return numeroDecimal;
    }
}


tipoCola* crearCola(void){
	tipoCola* cola = malloc(sizeof(tipoCola)); 
	if(cola == NULL) return NULL;
	cola->primero  =NULL;
	cola->ultimo = NULL;
	return cola;
}

void encolar(tipoCola* cola, char* cadena, int valor, char* categoria){
	NodoCola* nuevoNodo = (NodoCola*)malloc(sizeof(NodoCola));

    strcpy(nuevoNodo->info.nombre, cadena);
    nuevoNodo->info.cantidad = valor;
    strcpy(nuevoNodo->info.categoria, categoria);
	nuevoNodo->sgte = NULL;

	if (cola->primero == NULL)
		cola->primero = nuevoNodo;
	else
		cola->ultimo->sgte = nuevoNodo;
	
    cola->ultimo = nuevoNodo;	
}

struct infoCola desencolar(tipoCola *cola){
	if(cola->primero == NULL){
        fprintf(arcFinal,"\n La cola se encuentra vacia\n\n");
        cola->ultimo = NULL;
    }
    else {
        struct infoCola info;
        strcpy(info.nombre, cola->primero->info.nombre);
        info.cantidad = cola->primero->info.cantidad;
        strcpy(info.categoria, cola->primero->info.categoria); 

        NodoCola* aux = cola->primero;
        cola->primero = aux->sgte; 
        free(aux);
        return info;
    }	
}