%option noyywrap

%{
// Definimos las librerías que incluímos
#include <stdio.h>
#include <string.h>

typedef struct nodo{
    char nombre[32];    /* asumimos un tamaño para el identificador y el literal cadena de 31 caracteres + '\0' */
    int cantidad;
    struct nodo* sgte;
} Nodo;

//typedef struct identificador Nodo;


// Definicion de Variables Globales
Nodo* listaIdentificadores = NULL;
Nodo* listaLiteralCadena = NULL;
FILE* arcFinal;

/* Prototipo de FUNCIONES*/
int buscarCadena(Nodo*, char*);
void insertarPrimeroIdentificador(char*);
void insertarEnMedioIdentificador(char*);
void modificarIdentificador(char*);
void cargarSinRepetir(Nodo*, char*, int, int);
void insertarLiteralCadena(char*, int);
void imprimirListaIdentificadores(FILE*);
void imprimirListaLiteralCdena(FILE*);
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

\"(\\.|[^(\n|\\")])*\" {cargarSinRepetir(listaLiteralCadena, yytext, yyleng, 2);} 

char|double|enum|float|int|long|short|signed|struct|union|unsigned|void {printf("Encontre Palabre Reservada - TIPO DE DATO: %s \n",yytext);}
break|case|continue|do|else|for|goto|if|return|switch|while {printf("Encontre Palabra Reservada - ESTRUCTURA DE CONTROL: %s \n",yytext);}
auto|const|default|extern|register|sizeof|static|typedef|volatile {printf("Encontre Palabra Reservada - OTROS: %s \n",yytext);}

{IDENTIFICADOR} {cargarSinRepetir(listaIdentificadores, yytext, 0, 1);} 

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
    imprimirListaLiteralCdena(arcFinal);
	fclose(arcFinal);

    return 0;
}

int buscarCadena(Nodo* lista, char* identificador){
    Nodo* actual = lista;

    while(actual != NULL && (strcmp(identificador, actual->nombre) != 0))
        actual = actual->sgte;

    if(actual != NULL && (strcmp(identificador, actual->nombre) == 0))
        return 1;
	else
        return 0;
}

void insertarPrimeroIdentificador(char* identificador){
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    strcpy (nuevoNodo->nombre, identificador);
    nuevoNodo->cantidad = 1; 
    nuevoNodo->sgte = listaIdentificadores; 
    listaIdentificadores = nuevoNodo; 
}

void insertarEnMedioIdentificador(char* identificador){
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo)); 
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

void cargarSinRepetir(Nodo* lista, char* cadena, int longitudCadena, int identificador){
    int aux = buscarCadena(lista, cadena);

    switch (identificador){     /* identificador es un numero que fija que lexema se evaluara*/
        case 1:                 /* 1: IDENTIFICADOR */
            if(aux)
                modificarIdentificador(cadena);
            else
                insertarOrdenadoIdentificador(cadena);
            break;
        case 2:                 /* 2: LITERAL CADENA */
            if (aux == 0)
                insertarLiteralCadena(cadena, longitudCadena);
            break;
    }
}

void insertarLiteralCadena(char* cadena, int longitudCadena){
	Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));

    strcpy (nuevoNodo->nombre, cadena);
    nuevoNodo->cantidad = longitudCadena;

	if(listaLiteralCadena == NULL){
        nuevoNodo->sgte = listaLiteralCadena; 
        listaLiteralCadena = nuevoNodo;
	}
    else{
        Nodo* aux = listaLiteralCadena;

        while(aux->sgte != NULL)
            aux = aux->sgte; 
        
        nuevoNodo->sgte = NULL;
        aux->sgte = nuevoNodo;
	}
}

void imprimirLista(Nodo* lista, FILE* arcFinal){
    Nodo* actual = lista;

    if(lista != NULL){
        while(actual != NULL){
            fprintf (arcFinal, "%32s\t %d\n", actual->nombre, actual->cantidad);
            actual = actual->sgte;
        }
	}
    else
		fprintf(arcFinal,"\n La lista se encuentra vacia\n\n"); 
}

void imprimirListaIdentificadores(FILE* arcFinal){
    fprintf(arcFinal, "-----------------------------------------------------------------------\n");
    fprintf(arcFinal, "|                      Lista de Identificadores                       |\n");
    fprintf(arcFinal, "-----------------------------------------------------------------------\n");
    fprintf(arcFinal, "|                  Identificador  |  Cantidad de repeticiones         |\n");
    fprintf(arcFinal, "-----------------------------------------------------------------------\n");
    imprimirLista(listaIdentificadores, arcFinal);
    
    fprintf(arcFinal, "-----------------------------------------------------------------------\n");
}

void imprimirListaLiteralCdena(FILE* arcFinal){
    fprintf(arcFinal, "\n\nNOTA: el listado de literales cadenas no contine repeticiones");
    fprintf(arcFinal, "\n-----------------------------------------------------------------------\n");
    fprintf(arcFinal, "|                       Lista de literales Cadena                     |\n");
    fprintf(arcFinal, "-----------------------------------------------------------------------\n");
    fprintf(arcFinal, "|                 Literal Cadena  |  Longitud de la Cadena            |\n");
    fprintf(arcFinal, "-----------------------------------------------------------------------\n");

    imprimirLista(listaLiteralCadena, arcFinal);
    fprintf(arcFinal, "-----------------------------------------------------------------------\n");
}


