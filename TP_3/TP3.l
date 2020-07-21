%option noyywrap

%{
// Definimos las librerías que incluímos
#include <stdio.h>

// definicion de variables globales para nuestro analizador léxico
int acum = 0;
%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 

%%

[1-9]{DIGITO_DECIMAL}* {printf("Encontre la constante entera decimal que tiene como primer caracter: %s \n",yytext);}
0{DIGITO_OCTAL}* {printf("Encontre la constante entera octal que tiene como segundo caracter: %s \n",yytext);}
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontre la constante entera hexadecimal: %s \n",yytext);}

({LETRA}|'_')({LETRA}|{DIGITO_DECIMAL}|'_')* {printf("Encontre el identificador: %s \n",yytext);}

%%

int main() {
   
    /* Acciones previas a la invocación den analizador léxico */

    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	

    /* Invocación del analizador léxico */

    yylex();
	
    /* Acciónes posteriores a la ejecución del analizador léxico, 
    sirven por ejemplo, para hacer un informen de resumen.1 */

    printf ("La suma de las longitudes de todas las cadenas reconocidas es %d",acum);

    return 0;
}
