%option noyywrap

%{
// Definicion de las librerías que incluímos
#include <stdio.h>
#include <string.h> // strcpy, strcmp
#include <ctype.h>  // toupper y isdigit
#include <math.h>   // pow
#include <stdlib.h> // atoi, atof

// Deficinion de directivas de preprocesamiento
#define DECIMAL 0
#define OCTAL 1
#define HEXADECIMAL 2
#define CARACTER 3
#define REAL 4
#define LITERAL_CADENA 5
#define P_RESERVADA 6
#define IDENTIFICADOR 7
#define OPERADOR 8
#define PUNTUACION 9
#define COMENTARIO 10
#define DEFINE 11 
#define INCLUDE 12
#define NO_RECONOCIDOS 13

#define BASE8 8
#define BASE16 16


// Definicion de estructuras
typedef struct nodo{
    char nombre[32];    /* asumimos un tamaño para el identificador de 31 caracteres + '\0' = 32 */
    int cantidad;
    char categoria[20];
    struct nodo* sgte;
} Nodo;

struct infoCola{
    char nombre[101];    /* asumimos un tamaño para el literal cadena y de los comentarios de 100 caracteres + '\0' + " + " = 101 */
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


// Definicion de Variables Globales
Nodo* listaIdentificadores;
Nodo* listaOper_CarPunt;

tipoCola* LiteralCadena;
tipoCola* PalabrasReservadas;
tipoCola* decimales;
tipoCola* octales;
tipoCola* hexadecimales;
tipoCola* reales;
tipoCola* caracteres;
tipoCola* comentarios;
tipoCola* NoReconocidos;

int ACUMULADOR_DECIMALES = 0, CONTADOR_CARACTERES = 0, CONTADOR_SALTOS_DE_LINEA = 1, CONTADOR_DEFINE = 0, CONTADOR_INCLUDE = 0;
FILE* arcFinal;

/* Prototipo de FUNCIONES*/
int buscarCadena(Nodo*, char*);
void insertarPrimeroIdentificador(char*);
void insertarEnMedioIdentificador(char*);
void insertarOrdenadoIdentificador(char*);
void insertarLiteralCadena(char*, int);
void insertarOperador_Puntuacion(char*, char*);
void modificarNodo(Nodo*, char*);
void cargarSinRepetir(Nodo*, char*, int);
tipoCola* crearCola();
void encolar(tipoCola*, char*, int, char*);
struct infoCola desencolar(tipoCola*);
int caracterHexadecimalADecimal(char);
int convertirAdecimal(char*, int, int);
int contieneSaltoDeLinea(char*, int);

void imprimirLista(Nodo*, FILE*, int);
void imprimirCola(tipoCola*, FILE*, int);

void imprimirIdentificadores();
void imprimirLiteralesCadena();
void imprimirPalabrasReservadas();
void imprimirConstantes();
void imprimirOper_Y_CarPunt();
void imprimirComentarios();
void imprimirNoReconocidos();
void imprimirDirectivasPrecompilador();


%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z]
IDENTIFICADOR ({LETRA}|"_")({LETRA}|{DIGITO_DECIMAL}|"_")*
CONDICION (<|\")

%% 

[1-9]{DIGITO_DECIMAL}*  {ACUMULADOR_DECIMALES += atoi(yytext); encolar(decimales, yytext, 0, "Decimal");}
0{DIGITO_OCTAL}* { encolar(octales, yytext, convertirAdecimal(yytext, BASE8, yyleng), "Octal");}
0[xX]{DIGITO_HEXADECIMAL}+ { encolar(hexadecimales, yytext, convertirAdecimal(yytext, BASE16, yyleng), "Hexa");}
({DIGITO_DECIMAL}*\.{DIGITO_DECIMAL}+|{DIGITO_DECIMAL}+\.|{DIGITO_DECIMAL}+)([eE][\+\-]?{DIGITO_DECIMAL}+)? {encolar(reales, yytext, atof(yytext), "Real");}
\'.?\' {encolar(caracteres, yytext, (CONTADOR_CARACTERES += 1), "Caracter");}

\"(\\.|[^(\n|\\")])*\" { encolar(LiteralCadena, yytext, yyleng - 2, "");} 

char|double|enum|float|int|long|short|signed|struct|union|unsigned|void { encolar(PalabrasReservadas, yytext, 0, "Tipo de Dato");}
break|case|continue|do|else|for|goto|if|return|switch|while { encolar(PalabrasReservadas, yytext, 0, "Estructura de Control");}
auto|const|default|extern|register|sizeof|static|typedef|volatile { encolar(PalabrasReservadas, yytext, 0, "Otros");}

{IDENTIFICADOR} {cargarSinRepetir(listaIdentificadores, yytext, IDENTIFICADOR);} 

"++"|"--"|"->"|<=|==|!=|!!|&&|"||"|"+="|"-="|"*="|"/="|%=|>>=|<<=|&=|"|="|"^="|"?:"|<<|>>|"^"|[\+\-\*/%~&!=<>\|] { cargarSinRepetir(listaOper_CarPunt, yytext, OPERADOR);}
\.\.\.|[.|,|;|:|#|\[|\]|\{|\}|\(|\)] { cargarSinRepetir(listaOper_CarPunt, yytext, PUNTUACION);}

\/\*(\\.|[^\\*\/])*\*\/  {encolar(comentarios, yytext, 0, "Multiples Lineas"); contieneSaltoDeLinea(yytext, yyleng);}
\/\/(\\.|[^\n])*  {encolar(comentarios, yytext, 0, "1 Linea");}

"#define"/" "{IDENTIFICADOR} {CONTADOR_DEFINE += 1;}
"#include"/" "{CONDICION} {CONTADOR_INCLUDE += 1;}

"\n" {encolar(NoReconocidos, "\\n", CONTADOR_SALTOS_DE_LINEA, "" ); CONTADOR_SALTOS_DE_LINEA += 1;}
. {encolar(NoReconocidos, yytext, CONTADOR_SALTOS_DE_LINEA, "" );}

%%

int main() {
   
    /* Acciones previas a la invocación del analizador léxico */

    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");
    arcFinal = fopen ("Informe.txt", "w");

    // Inicializacion de las estructuras enlazadas
    listaIdentificadores = NULL;
    listaOper_CarPunt = NULL;

    LiteralCadena = crearCola();
    PalabrasReservadas = crearCola();
    decimales = crearCola();
    octales = crearCola();
    hexadecimales = crearCola();
    caracteres = crearCola ();
    reales = crearCola();
    comentarios = crearCola();
    NoReconocidos = crearCola();

    /* Invocación del analizador léxico */
    yylex();

    /* Acciónes posteriores a la ejecución del analizador léxico */

    fprintf(arcFinal, "                             INFORME - FLEX para reconocimiento de categorías léxicas de C                               \n\n");
    fprintf(arcFinal, "-------------------------------------------------------------------------------------------------------------------------\n\n");
    imprimirIdentificadores();
    imprimirLiteralesCadena();
    imprimirPalabrasReservadas();
    imprimirConstantes();
    imprimirOper_Y_CarPunt();
    imprimirComentarios();
    imprimirNoReconocidos();
    imprimirDirectivasPrecompilador();

	fclose(arcFinal);
    return 0;
}

int buscarCadena(Nodo* lista, char* cadena){
    Nodo* actual = lista;

    while(actual != NULL && (strcmp(cadena, actual->nombre) != 0))
        actual = actual->sgte;

    if(actual != NULL && (strcmp(cadena, actual->nombre) == 0))
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

void insertarOperador_Puntuacion(char* cadena, char* categoria){
	Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    strcpy (nuevoNodo->nombre, cadena);
    nuevoNodo->cantidad = 1;
    strcpy (nuevoNodo->categoria, categoria);

	if(listaOper_CarPunt == NULL){
        nuevoNodo->sgte = listaOper_CarPunt; 
        listaOper_CarPunt = nuevoNodo;
	}
    else{
        Nodo* aux = listaOper_CarPunt;

        while(aux->sgte != NULL)
            aux = aux->sgte; 
        nuevoNodo->sgte = NULL;
        aux->sgte = nuevoNodo;
	}
}

void modificarNodo(Nodo* lista, char* cadena){
	Nodo* actual = lista;
	int encontrado = 0;

	if(lista != NULL){
		while(actual != NULL && encontrado != 1){
			if(strcmp(cadena, actual->nombre) == 0){
				actual->cantidad += 1;
				encontrado = 1;
			}
            else	
			    actual = actual->sgte;
		}
	}
}

void cargarSinRepetir(Nodo* lista, char* cadena, int token){
    int aux = buscarCadena(lista, cadena);
               
    if(aux)
        modificarNodo(lista, cadena);
    else{
        switch (token){
            case IDENTIFICADOR:
                insertarOrdenadoIdentificador(cadena);
                break;
            case OPERADOR:
                insertarOperador_Puntuacion(cadena, "Operador");
                break;
            case PUNTUACION:
                insertarOperador_Puntuacion(cadena, "Puntuacion");
        }
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

int contieneSaltoDeLinea(char* cadena, int longitud){
    for(int i = 0; i < longitud; i++){
        if(cadena[i] == '\n')
            CONTADOR_SALTOS_DE_LINEA += 1;
    }
}

void imprimirLista(Nodo* lista, FILE* arcFinal, int token){
    Nodo* actual = lista;

    if(lista != NULL){
        while(actual != NULL){
            switch (token){
            case IDENTIFICADOR:
                fprintf (arcFinal, "|\t%-32s\t|%15d%14s|\n", actual->nombre, actual->cantidad," ");
                break;
            case OPERADOR ... PUNTUACION:
                fprintf (arcFinal, "|\t\t %-9s\t|\t%4d\t\t|\t%-22s\t|\n", actual->nombre, actual->cantidad, actual->categoria);
                break;
            }
            actual = actual->sgte;
        }
	}
    else
		fprintf(arcFinal,"\n La lista se encuentra vacia\n\n"); 
}



void imprimirCola(tipoCola* cola, FILE* arcFinal, int categoria){
    struct infoCola info;
    
    if(cola->primero != NULL){
        while(cola->primero != NULL){
            info = desencolar(cola);
            float mantisa = atof(info.nombre);

            switch (categoria){
                case DECIMAL:
                    fprintf (arcFinal, "|%20s\t|\t%-37s\t|\n", info.nombre, info.categoria);
                    break;
                case OCTAL ... CARACTER:
                    fprintf (arcFinal, "|%20s\t|\t%8d\t|\t%-22s\t|\n", info.nombre, info.cantidad, info.categoria);
                    break;
                case REAL:
                    fprintf (arcFinal, "|%20s\t|\t%8d\t|\t%.5f\t|\t%-9s\t|\n", info.nombre, info.cantidad, mantisa - info.cantidad, info.categoria);
                    break;                                                                                 
                case LITERAL_CADENA:
                    fprintf (arcFinal, "|\t%-100s\t|\t%-4d\t |\n", info.nombre, info.cantidad);  
                    break;
                case P_RESERVADA:
                    fprintf (arcFinal, "|\t%17s\t|\t%-37s\t|\n", info.nombre, info.categoria);  
                    break;
                case COMENTARIO:
                    fprintf (arcFinal, "| %-100s | %-16s |\n", info.nombre, info.categoria);
                    break;
                case NO_RECONOCIDOS:
                    if(strcmp(info.nombre, " ")  != 0)
                        fprintf (arcFinal, "|%30s\t|\t%-30d|\n", info.nombre, info.cantidad);
                    else
                        fprintf (arcFinal, "|%30s\t|\t%-30d|\n", "espacio", info.cantidad);
                    break;
            }       
        }
	}
    else
		fprintf(arcFinal,"\n La cola se encuentra vacia\n\n");
}


void imprimirIdentificadores(){
    fprintf(arcFinal, "_______________________________________________________________________\n");
    fprintf(arcFinal, "|                      Lista de Identificadores                       |\n");
    fprintf(arcFinal, "|_____________________________________________________________________|\n");
    fprintf(arcFinal, "|                 Lexema                |        Nro Repeticiones     |\n");
    fprintf(arcFinal, "|_______________________________________|_____________________________|\n");
    imprimirLista(listaIdentificadores, arcFinal, IDENTIFICADOR);
    
    fprintf(arcFinal, "|_______________________________________|_____________________________|\n\n");
}

void imprimirLiteralesCadena(){
    fprintf(arcFinal, "\n\n__________________________________________________________________________________________________________________________\n");
    fprintf(arcFinal, "|                                                   Lista de literales Cadena                                            |\n");
    fprintf(arcFinal, "|________________________________________________________________________________________________________________________|\n");
    fprintf(arcFinal, "|                                                     Lexema                                                  | Longitud |\n");
    fprintf(arcFinal, "|_____________________________________________________________________________________________________________|__________|\n");

    imprimirCola(LiteralCadena, arcFinal, LITERAL_CADENA);
    fprintf(arcFinal, "|_____________________________________________________________________________________________________________|__________|\n\n");
}

void imprimirPalabrasReservadas(){
    fprintf(arcFinal, "\n\n_______________________________________________________________________\n");
    fprintf(arcFinal, "|                    Lista de Palabras Reservadas                     |\n");
    fprintf(arcFinal, "|_____________________________________________________________________|\n");
    fprintf(arcFinal, "|             Lexema     |                 Categoria                  |\n");
    fprintf(arcFinal, "|________________________|____________________________________________|\n");

    imprimirCola(PalabrasReservadas, arcFinal, P_RESERVADA);
    fprintf(arcFinal, "|________________________|____________________________________________|\n\n");
}

void imprimirConstantes(){
    fprintf(arcFinal, "\n\n_______________________________________________________________________\n");
    fprintf(arcFinal, "|                            Lista de Constantes                      |\n");
    fprintf(arcFinal, "|_____________________________________________________________________|\n");
    fprintf(arcFinal, "|              Lexema    |     Token                                  |\n");
    fprintf(arcFinal, "|------------------------|--------------------------------------------|\n");
    imprimirCola(decimales, arcFinal, DECIMAL);
    fprintf(arcFinal, "|          ---------------                                            |\n");
    fprintf(arcFinal, "| TOTAL \t%10d                                                  |\n|%69s|\n", ACUMULADOR_DECIMALES, " ");

    fprintf(arcFinal, "|---------------------------------------------------------------------|\n");
    fprintf(arcFinal, "|              Lexema    |  Val Decimal |     Token                   |\n");
    fprintf(arcFinal, "|------------------------|--------------|-----------------------------|\n");
    imprimirCola(octales, arcFinal, OCTAL);
    imprimirCola(hexadecimales, arcFinal, HEXADECIMAL);
    fprintf(arcFinal, "|%69s|\n", " ");

    fprintf(arcFinal, "|---------------------------------------------------------------------|\n");
    fprintf(arcFinal, "|              Lexema    | Parte Entera |    Mantisa   |    Token     |\n");
    fprintf(arcFinal, "|------------------------|--------------|--------------|--------------|\n");
    imprimirCola(reales, arcFinal, REAL);
    fprintf(arcFinal, "|%69s|\n", " ");    
    
    fprintf(arcFinal, "|---------------------------------------------------------------------|\n");
    fprintf(arcFinal, "|              Lexema    | Or aparicion |     Token                   |\n");
    fprintf(arcFinal, "|------------------------|--------------|-----------------------------|\n");
    imprimirCola(caracteres, arcFinal, CARACTER);
    
    fprintf(arcFinal, "|________________________|______________|_____________________________|\n");
}

void imprimirOper_Y_CarPunt(){
    fprintf(arcFinal, "\n\n_______________________________________________________________________\n");
    fprintf(arcFinal, "|            Lista de Operadores y Caracteres de Puntuacion           |\n");
    fprintf(arcFinal, "|_____________________________________________________________________|\n");
    fprintf(arcFinal, "|        Lexema          | Repeticiones |     Token                   |\n");
    fprintf(arcFinal, "|________________________|______________|_____________________________|\n");
    imprimirLista(listaOper_CarPunt, arcFinal, OPERADOR);
    
    fprintf(arcFinal, "|________________________|______________|_____________________________|\n");
}

void imprimirComentarios(){
    fprintf(arcFinal, "\n\n___________________________________________________________________________________________________________________________\n");
    fprintf(arcFinal, "|                                                    Lista de Comentarios                                                 |\n");
    fprintf(arcFinal, "|_________________________________________________________________________________________________________________________|\n");
    fprintf(arcFinal, "|                                                     Lexema                                           |      Token       |\n");
    fprintf(arcFinal, "|______________________________________________________________________________________________________|__________________|\n");
    imprimirCola(comentarios, arcFinal, COMENTARIO);
    
    fprintf(arcFinal, "|______________________________________________________________________________________________________|__________________|\n\n");
}

void imprimirNoReconocidos(){
    fprintf(arcFinal, "\n\nNOTA: Asumimos que no habra cadenas no reconocidas, ya que segun las reglas pueden ser catalogadas como identificador, \n\t literal cadena, comentario o palabra reservada, por lo tanto, nos enfocamos en los caracteres que no son reconocidos.");
    fprintf(arcFinal, "\n\n_______________________________________________________________________\n");
    fprintf(arcFinal, "|         Listado de cadenas y/o caracteres NO reconocidos            |\n");
    fprintf(arcFinal, "|_____________________________________________________________________|\n");
    fprintf(arcFinal, "|                        Lexema    |    Nro de linea                  |\n");
    fprintf(arcFinal, "|__________________________________|__________________________________|\n");
    imprimirCola(NoReconocidos, arcFinal, NO_RECONOCIDOS);
    
    fprintf(arcFinal, "|__________________________________|__________________________________|\n");
}

void imprimirDirectivasPrecompilador(){
    fprintf(arcFinal, "\n\n_______________________________________________________________________\n");
    fprintf(arcFinal, "|               Listado de directivas del Precompilador               |\n");
    fprintf(arcFinal, "|_____________________________________________________________________|\n");
    fprintf(arcFinal, "|                        Lexema    |    Nro repeticiones              |\n");
    fprintf(arcFinal, "|__________________________________|__________________________________|\n");
    fprintf(arcFinal, "|%30s\t|\t%-30d|\n", "#define", CONTADOR_DEFINE);
    fprintf(arcFinal, "|%30s\t|\t%-30d|\n", "#include", CONTADOR_INCLUDE);
    
    fprintf(arcFinal, "|__________________________________|__________________________________|");
}
