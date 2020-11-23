%option noyywrap
%option yylineno

%{
#include "TPBison.tab.h"
#include "TPIntegrador.h"

nodoError* listaErroresLexicos = NULL;

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
IDENTIFICADOR ({LETRA}|_)({LETRA}|{DIGITO_DECIMAL}|_)*
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

[^ ]  {agregar_error_lexico(&listaErroresLexicos, yytext, yylineno);}  


%%
