%option noyywrap

%{
#include "TP4Bison.tab.h"

// Definicion de las librerías que incluímos
#include <stdio.h>
#include <string.h> // strcpy, strcmp
#include <ctype.h>  // toupper y isdigit
#include <math.h>   // pow
#include <stdlib.h> // atoi, atof
#include "TP4.h"

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
ESTRUCTURA_DE_CONTROL continue|goto
PALABRA_RESERVADA auto|enum|extern|register|sizeof|struct|typedef|union
OPERADOR [\+\-\*\/\%]|\+\+|\-\-

%% 

[1-9]{DIGITO_DECIMAL}*  {yylval.num = atoi(yytext); return NUM;}
0{DIGITO_OCTAL}* {yylval.num = convertirAdecimal(yytext, BASE8, yyleng); return NUM;}
0[xX]{DIGITO_HEXADECIMAL}+ {yylval.num = convertirAdecimal(yytext, BASE16, yyleng); return NUM;}
({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+|{DIGITO_DECIMAL}+\.|{DIGITO_DECIMAL}+)([eE][\+\-]?{DIGITO_DECIMAL}+)? {yylval.real = atoi(yytext); return REAL;}
\'.?\' {yylval.caracter = atoi(yytext); return CCARACTER;}

\"(\\.|[^(\n|\\")])*\" {strcpy(yylval.cadena,yytext); return LIT_CADENA;} 

{TIPO_DATO} {strcpy(yylval.cadena,yytext); return TIPO_DATO;}
{ESTRUCTURA_DE_CONTROL} {strcpy(yylval.cadena,yytext); return ESTRUCTURA_DE_CONTROL;}
{PALABRA_RESERVADA} {strcpy(yylval.cadena,yytext); return PALABRA_RESERVADA;}

{IDENTIFICADOR} {strcpy(yylval.cadena,yytext); return IDENTIFICADOR;} 

{OPERADOR} {yylval.caracter = atoi(yytext); return OPERADOR}
/*"++"|"--"|"->"|<=|==|!=|!!|&&|"||"|"+="|"-="|"*="|"/="|%=|>>=|<<=|&=|"|="|"^="|"?:"|<<|>>|"^"|[\+\-\*/    /*%~&!=<>\|] { cargarSinRepetir(listaOper_CarPunt, yytext, OPERADOR);}
/*\.\.\.|[.|,|;|:|#|\[|\]|\{|\}|\(|\)] { cargarSinRepetir(listaOper_CarPunt, yytext, PUNTUACION);}

\/\*(\\.|[^\\*\/])*\*\/  {strcpy(yylval.cadena,yytext); return COMENTARIO;}
\/\/(\\.|[^\n])*  {strcpy(yylval.cadena,yytext); return COMENTARIO;}

"#define"/" "{IDENTIFICADOR} {CONTADOR_DEFINE += 1;}
"#include"/" "{CONDICION} {CONTADOR_INCLUDE += 1;}

"for" {strcpy(yylval.cadena,yytext); return FOR;}
"while" {strcpy(yylval.cadena,yytext); return WHILE;}
"do" {strcpy(yylval.cadena,yytext); return DO;}
"switch" {strcpy(yylval.cadena,yytext); return SWITCH;}
"break" {strcpy(yylval.cadena,yytext); return BREAK;}
"case" {strcpy(yylval.cadena,yytext); return CASE;}
"default" {strcpy(yylval.cadena,yytext); return DEFAULT;}
"return" {strcpy(yylval.cadena,yytext); return RETURN;}
"if" {strcpy(yylval.cadena,yytext); return IF;}
"else" {strcpy(yylval.cadena,yytext); return ELSE;}


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