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
[1-9]{DIGITO_DECIMAL}* {printf("Encontre la constante entera decimal: %s \n",yytext);}
0{DIGITO_OCTAL}* {printf("Encontre la constante entera octal: %s \n",yytext);}
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontre la constante entera hexadecimal: %s \n",yytext);}
({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+|{DIGITO_DECIMAL}+\.|{DIGITO_DECIMAL}+)([eE]['+'\-]?{DIGITO_DECIMAL}+)? {printf("Encontre la constante real: %s \n",yytext);}
\'.\' {printf("Encontre la constante Caracter: %s \n",yytext);}

\"(\\.|[^\\"])*\" {printf("Encontre Literal Cadena: %s \n",yytext);}

char|double|enum|float|int|long|short|signed|struct|union|unsigned|void {printf("Encontre Palabre Reservada - TIPO DE DATO: %s \n",yytext);}
break|case|continue|do|else|for|goto|if|return|switch|while {printf("Encontre Palabra Reservada - ESTRUCTURA DE CONTROL: %s \n",yytext);}
auto|const|default|extern|register|sizeof|static|typedef|volatile {printf("Encontre Palabra Reservada - OTROS: %s \n",yytext);}

({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")* {printf("Encontre el identificador: %s \n",yytext);} 


,|;|:|\.|#|\{|\}|\(|\)|\[|\]|... {printf("Encontre caracter de puntuacion: %c \n",yytext);}


%% 

int main() {
   
    /* Acciones previas a la invocación den analizador léxico */

    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	

    /* Invocación del analizador léxico */

    yylex();
	
    /* Acciónes posteriores a la ejecución del analizador léxico, 
    sirven por ejemplo, para hacer un informen de resumen.1 */

    printf("La suma de las longitudes de todas las cadenas reconocidas es %d",acum);

    return 0;
}