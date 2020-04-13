#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    //  Lee el archivo .txt y almacena en una lista cada una de las palabras separadas por ','.

    char *list[200];
    char * s = ",";
    
    FILE *lista;
    lista = fopen("entrada.txt", "r");

    int MAX_FILE_SIZE = 1000;
    
    char * buffer = (char*)malloc(sizeof(char)*MAX_FILE_SIZE);

    fread(buffer, sizeof(char), MAX_FILE_SIZE, lista);
    
    list[0] = strtok(buffer, s);

    for (int i = 1;; i++){
        list[i] = strtok(NULL, s); // Pag 274 Libro C
        if (list[i] == NULL) {
        break;
        }
    }

fclose(lista);

// list contiene las palabras ingresadas mediante el archivo.txt

printf(list[1]); 
printf(list[0]);

// Falta hacer: Función "Automata" que reciba como parametro un string, haga que el automata (matriz) lo clasifique, y devuelva el string con su correspondiente clasificación. 
// Ej: Toma "1234" Devuelve "1234 Decimal"











}   