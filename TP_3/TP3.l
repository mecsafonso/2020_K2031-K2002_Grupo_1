%option noyywrap

%{
// Definimos las librerías que incluímos
#include <stdio.h>
#include <string.h>

typedef struct identificador{
    char nombre[32];
    int cantidad;
    struct identificador* sgte;
} Nodo;

//typedef struct identificador Nodo;


// Definicion de Variables Globales
Nodo* listaIdentificadores = NULL;
Nodo* ultimo = NULL;
FILE* arcFinal;

/* Prototipo de FUNCIONES*/
int buscarIdentificador(char*);
void insertarPrimeroIdentificador(char*);
void insertarEnMedioIdentificador(char*);
void modificarIdentificador(char*);
void cargarSinRepetirIdentificador(char*);
void imprimirListaIdentificadores(FILE*);


%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
IDENTIFICADOR ({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")*
CONDICION (<|\")
ESPACIO " " 

%% 
[1-9]{DIGITO_DECIMAL}* {printf("Encontre la constante entera decimal: %s \n",yytext);}
0{DIGITO_OCTAL}* {printf("Encontre la constante entera octal: %s \n",yytext);}
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontre la constante entera hexadecimal: %s \n",yytext);}
({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+|{DIGITO_DECIMAL}+\.|{DIGITO_DECIMAL}+)([eE][\+\-]?{DIGITO_DECIMAL}+)? {printf("Encontre la constante real: %s \n",yytext);}
\'.?\' {printf("Encontre la constante Caracter: %s \n",yytext);}

\"(\\.|[^(\n|\\")])*\" {printf("Encontre Literal Cadena: %s \n",yytext);} 

char|double|enum|float|int|long|short|signed|struct|union|unsigned|void {printf("Encontre Palabre Reservada - TIPO DE DATO: %s \n",yytext);}
break|case|continue|do|else|for|goto|if|return|switch|while {printf("Encontre Palabra Reservada - ESTRUCTURA DE CONTROL: %s \n",yytext);}
auto|const|default|extern|register|sizeof|static|typedef|volatile {printf("Encontre Palabra Reservada - OTROS: %s \n",yytext);}

{IDENTIFICADOR} {cargarSinRepetirIdentificador(yytext);} 

"++"|"--"|"->"|<=|==|!=|!!|&&|"||"|"+="|"-="|"*="|"/="|%=|>>=|<<=|&=|"|="|"^="|"?:"|<<|>>|[\+\-\*/%~&!\^=<>\|] {printf("Encontre el operador: %s \n",yytext);}
\.\.\.|[.|,|;|:|#|\[|\]|\{|\}|\(|\)] {printf("Encontre el caracter de puntuacion: %s \n",yytext);}

\/\*(\\.|[^\\*\/])*\*\/  {printf("Encontre un comentario de multiples lineas: %s \n",yytext);}
\/\/(\\.|[^\n])*  {printf("Encontre un comentario de una linea linea: %s \n",yytext);}

^"#define "/{IDENTIFICADOR} {printf("Encontre una direccion de PREPROCESAMIENTO - DEFINE: %s \n",yytext);}
^"#include "/{CONDICION} {printf("Encontre una direccion de PREPROCESAMIENTO - INCLUDE: %s \n",yytext);}

(\\.|^{ESPACIO}) {printf( "Caracter no reconocido: %s\n", yytext );}


%%
int main() {
   
    /* Acciones previas a la invocación den analizador léxico */
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");
    arcFinal = fopen ("Informe.txt", "w");

    /* Invocación del analizador léxico */
    yylex();

    /* Acciónes posteriores a la ejecución del analizador léxico */
    imprimirListaIdentificadores(arcFinal);
	fclose(arcFinal);

    return 0;
}

int buscarIdentificador(char* identificador){
    Nodo* actual = listaIdentificadores;

    while(actual != NULL && (strcmp(identificador, actual->nombre) != 0))
        actual = actual->sgte;

    if(actual != NULL && (strcmp(identificador, actual->nombre) == 0))
        return 1;
	else
        return 0;
}

void insertarPrimeroIdentificador(char* identificador){
    Nodo* nuevoNodo = (struct identificador*) malloc(sizeof(struct identificador));
    strcpy (nuevoNodo->nombre, identificador);
    nuevoNodo->cantidad = 1; 
    nuevoNodo->sgte = listaIdentificadores; 
    listaIdentificadores = nuevoNodo; 
}

void insertarEnMedioIdentificador(char* identificador){
    Nodo* nuevoNodo = (struct identificador*) malloc(sizeof(struct identificador)); 
    Nodo*aux = listaIdentificadores; 
    strcpy (nuevoNodo->nombre, identificador);
    nuevoNodo->cantidad = 1; 

    while(aux->sgte != NULL && (strcmp(identificador, aux->sgte->nombre) > 0)){ 
        aux = aux->sgte; 
    } 
    
    nuevoNodo->sgte = aux->sgte; 
    aux->sgte = nuevoNodo; 
}


void insertarOrdenadoIdentificador(char* identificador){
    if (listaIdentificadores == NULL || (strcmp(listaIdentificadores->nombre, identificador) > 0)) 
        insertarPrimeroIdentificador(identificador);
    else 
        insertarEnMedioIdentificador(identificador);
}


void modificarIdentificador(char* identificador){
	Nodo* actual = listaIdentificadores;
	int encontrado = 0;

	if(listaIdentificadores != NULL){
		while(actual != NULL && encontrado != 1){
			if(strcmp(identificador, actual->nombre) == 0){
				actual->cantidad += 1;
				encontrado = 1;
			}
            else	
			    actual = actual->sgte;
		}
	}
}


void cargarSinRepetirIdentificador(char* identificador){
    int aux = buscarIdentificador(identificador);

    if(aux)
        modificarIdentificador(identificador);
    else
        insertarOrdenadoIdentificador(identificador);
}

void imprimirListaIdentificadores(FILE* arcFinal){
    Nodo* actual = listaIdentificadores;
    fprintf(arcFinal, "-----------------------------------------------------\n");
    fprintf(arcFinal, "|              Lista de Identificadores             |\n");
    fprintf(arcFinal, "-----------------------------------------------------\n");

    if(listaIdentificadores != NULL){
        while(actual != NULL){
            fprintf (arcFinal, "%32s\t %d\n", actual->nombre, actual->cantidad);
            actual = actual->sgte;
        }
	}
    else
		fprintf(arcFinal,"\n La lista se encuentra vacia\n\n"); 

    fprintf(arcFinal, "-----------------------------------------------------\n");
}