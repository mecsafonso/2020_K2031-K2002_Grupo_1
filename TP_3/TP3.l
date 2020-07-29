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

/* Prototipo de FUNCIONES*/
Nodo* crearNodo();
Nodo* buscar(Nodo*, char* );
Nodo* insertarOrdenadoIdentificador (char*, Nodo*);
Nodo* cargarSinRepetir(Nodo*, char*);
void imprimirLista(Nodo*, FILE*);

// definicion de variables globales para nuestro analizador léxico
Nodo* listaIdentificadores = NULL;

FILE* arcFinal;
int acum = 0;



%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
IDENTIFICADOR ({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")*
CONDICION (<|\") 

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

{IDENTIFICADOR} {cargarSinRepetir(listaIdentificadores, yytext);} 

"++"|"--"|"->"|<=|==|!=|!!|&&|"||"|"+="|"-="|"*="|"/="|%=|>>=|<<=|&=|"|="|"^="|"?:"|<<|>>|[\+\-\*/%~&!\^=<>\|] {printf("Encontre el operador: %s \n",yytext);}
\.\.\.|[.|,|;|:|#|\[|\]|\{|\}|\(|\)] {printf("Encontre el caracter de puntuacion: %s \n",yytext);}

\/\*(\\.|[^\\*\/])*\*\/  {printf("Encontre un comentario de multiples lineas: %s \n",yytext);}
\/\/(\\.|[^\n])*  {printf("Encontre un comentario de una linea linea: %s \n",yytext);}

^"#define "/{IDENTIFICADOR} {printf("Encontre una direccion de PREPROCESAMIENTO - DEFINE: %s \n",yytext);}
^"#include "/{CONDICION} {printf("Encontre una direccion de PREPROCESAMIENTO - INCLUDE: %s \n",yytext);}


%%



int main() {
   
    /* Acciones previas a la invocación den analizador léxico */

    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");

    arcFinal = fopen ("salida.txt", "w");

    fprintf (arcFinal, "\t %s.\n", yyout);	

    /* Invocación del analizador léxico */

    yylex();

    imprimirLista(listaIdentificadores, arcFinal);
	
    /* Acciónes posteriores a la ejecución del analizador léxico */

    printf("La suma de las longitudes de todas las cadenas reconocidas es %d",acum);

    return 0;
}

Nodo* crearNodo(void) {
  return (struct identificador*) malloc(sizeof(struct identificador));     //Asignacion de memoria dinamica -> en tiempo de ejecución
}

Nodo* buscar(Nodo* listaIdentificadores, char* identificador){
    Nodo* aux = listaIdentificadores;

    while(aux != NULL && (strcmp(identificador, aux->nombre)>0))
        aux = aux->sgte;

    if(aux != NULL && (strcmp(identificador, aux->nombre)==0))
        return aux;
    
    return NULL;
}

Nodo* insertarOrdenadoIdentificador(char* identificador, Nodo* listaIdentificadores){
    Nodo *nuevoNodo = crearNodo();	
    strcpy (nuevoNodo->nombre, identificador);
    nuevoNodo->cantidad = 0;
    
    if (listaIdentificadores == NULL || strcmp(listaIdentificadores->sgte->nombre, identificador) > 0) {
        nuevoNodo->sgte = listaIdentificadores;
        listaIdentificadores = nuevoNodo;
    }
    else {
        Nodo* aux = listaIdentificadores;
        while(strcmp(identificador, aux->sgte->nombre)>0 && aux->sgte != NULL)
            aux = aux->sgte;
        
        nuevoNodo->cantidad += 1;
        nuevoNodo->sgte = aux->sgte;
        aux->sgte = nuevoNodo;
    }
    return nuevoNodo;
}

Nodo* cargarSinRepetir(Nodo* listaIdentificadores, char* identificador){
    Nodo* aux = buscar(listaIdentificadores, identificador);

    if(aux == NULL)
        aux = insertarOrdenadoIdentificador(identificador, listaIdentificadores);
    
    return aux;
}

void imprimirLista(Nodo* listaIdentificadores, FILE* arcFinal){
    Nodo* aux;
    while( aux!=NULL ) { 
        fprintf (arcFinal, "\t %s.\n", aux->nombre);
        fprintf (arcFinal, "\t %d.\n", aux->cantidad);
        aux = aux->sgte; 
    }   
}


