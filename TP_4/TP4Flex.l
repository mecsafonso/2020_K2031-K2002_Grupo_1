%option noyywrap

%{
#include "TP4Bison.tab.h"

// Definicion de las librerías que incluímos
#include <stdio.h>
#include <string.h> // strcpy, strcmp
#include <ctype.h>  // toupper y isdigit
#include <math.h>   // pow
#include <stdlib.h> // atoi, atof

#define BASE8 8
#define BASE16 16

int caracterHexadecimalADecimal(char);
int convertirAdecimal(char*, int, int);

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
IDENTIFICADOR ({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")*
CONDICION (<|\")
TIPO_DATO char\*|char|const|double|float|int|long|short|signed|static|unsigned|void|volatile

PALABRA_RESERVADA auto|default|enum|extern|register|typedef|union
OPERADOR [\+\-\*\/\%]|\+\+|\-\-

%% 

[1-9]{DIGITO_DECIMAL}*  {yylval.entero = atoi(yytext); return NUM;}
0{DIGITO_OCTAL}* {yylval.entero = convertirAdecimal(yytext, BASE8, yyleng); return NUM;}
0[xX]{DIGITO_HEXADECIMAL}+ {yylval.entero = convertirAdecimal(yytext, BASE16, yyleng); return NUM;}

({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+|{DIGITO_DECIMAL}+\.|{DIGITO_DECIMAL}+)([eE][\+\-]?{DIGITO_DECIMAL}+)? {yylval.real = atof(yytext); return CONS_REAL;}

"'"."'" {return CARACTER;}            
","     {return ',';}
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
"!"     {return OPER_NEGACION;}
"&"     {return OPER_DIRECCION;}
\n	{return '\n';}

\"(\\.|[^(\n|\\")])*\" {strcpy(yylval.cadena,yytext); return LIT_CADENA;} 

"for"       {strcpy(yylval.cadena,yytext); return FOR;}
"while"     {strcpy(yylval.cadena,yytext); return WHILE;}
"do"        {strcpy(yylval.cadena,yytext); return DO;}
"switch"    {strcpy(yylval.cadena,yytext); return SWITCH;}
"break"     {strcpy(yylval.cadena,yytext); return BREAK;}
"case"      {strcpy(yylval.cadena,yytext); return CASE;}
"default"   {strcpy(yylval.cadena,yytext); return DEFAULT;}
"return"    {strcpy(yylval.cadena,yytext); return RETURN;}
"if"        {strcpy(yylval.cadena,yytext); return IF;}
"else"      {strcpy(yylval.cadena,yytext); return ELSE;}
"sizeof"    {strcpy(yylval.cadena,yytext); return SIZEOF;}
"continue"  {strcpy(yylval.cadena,yytext); return CONTINUE;}
"goto"      {strcpy(yylval.cadena,yytext); return GOTO;}
"struct"    {strcpy(yylval.cadena,yytext); return STRUCT;}

{TIPO_DATO} {strcpy(yylval.cadena,yytext); return TIPO_DATO;}
 
{IDENTIFICADOR} {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;} 


%%

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