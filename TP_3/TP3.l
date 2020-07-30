%option noyywrap

%{
// Definimos las librerías que incluímos
#include <stdio.h>
#include <string.h>

struct identificador{
    char nombre[32];
    int cantidad;
    struct identificador* sgte;
};

typedef struct identificador Nodo;


// definicion de variables globales para nuestro analizador léxico
Nodo* listaIdentificadores = NULL;
Nodo* inicio = NULL;
Nodo* fin = NULL;



FILE* arcFinal;

/* Prototipo de FUNCIONES*/
Nodo* buscar(Nodo*, char*);
Nodo* insertarOrdenadoIdentificador(Nodo*, char*);
Nodo* modificarListaIdentificador(Nodo*, char*);
Nodo* cargarSinRepetir(Nodo*, char*);
void imprimirLista(Nodo*, FILE*);


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

{IDENTIFICADOR} {fprintf(arcFinal,"identificador: %s \n",yytext); cargarSinRepetir(listaIdentificadores, yytext); imprimirLista(listaIdentificadores, arcFinal);} 

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

    imprimirLista(listaIdentificadores, arcFinal);
	
    /* Acciónes posteriores a la ejecución del analizador léxico */
   
    fclose(arcFinal);
    //system("pause");

    return 0;
}


Nodo* buscar(Nodo* listaIdentificadores, char* identificador){
    Nodo* aux = listaIdentificadores;

    while(aux != NULL && (strcmp(identificador, aux->nombre) != 0))
        aux = aux->sgte;

    if(aux != NULL && (strcmp(identificador, aux->nombre) == 0))
        return aux;
	else
        return NULL;
}

Nodo* insertarOrdenadoIdentificador(Nodo* listaIdentificadores, char* identificador){
    Nodo *nuevoNodo = (struct identificador*) malloc(sizeof(struct identificador));
    
    strcpy (nuevoNodo->nombre, identificador);
    nuevoNodo->cantidad = 0;
    nuevoNodo->sgte = listaIdentificadores; 
    listaIdentificadores = nuevoNodo; 
    return nuevoNodo;
}

Nodo* modificarListaIdentificador(Nodo* listaIdentificadores, char* identificador){
	Nodo* actual = (struct identificador*) malloc(sizeof(struct identificador));
	actual = listaIdentificadores;
	int encontrado = 0;

	if(listaIdentificadores != NULL){
		while(actual != NULL && encontrado != 1){
			if(strcmp(identificador, actual->nombre) == 0){
				actual->cantidad = actual->cantidad + 1;
				encontrado = 1;
                return actual;
			}	
			actual = actual->sgte;
		}
	}
}

Nodo* cargarSinRepetir(Nodo* listaIdentificadores, char* identificador){
    Nodo* aux = (struct identificador*) malloc(sizeof(struct identificador));
    aux = buscar(listaIdentificadores, identificador);

    if(aux == NULL)
        aux = insertarOrdenadoIdentificador(listaIdentificadores, identificador);
    else
        aux = modificarListaIdentificador(listaIdentificadores, identificador);
    
    return aux;
}

void imprimirLista(Nodo* listaIdentificadores, FILE* arcFinal){
    Nodo* aux = listaIdentificadores;
    fprintf(arcFinal, "-----------------------------------------------------\n");
    fprintf(arcFinal, "|              Lista de Identificadores             |\n");
    fprintf(arcFinal, "-----------------------------------------------------\n");
    
    while( aux != NULL ){ 
        fprintf (arcFinal, "\t %s", aux->nombre);
        fprintf (arcFinal, "\t %d \n", aux->cantidad);
        aux = aux->sgte; 
    }   
}