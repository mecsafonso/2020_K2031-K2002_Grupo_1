#include <stdio.h>
#include <string.h>

void main()
{
    //  Lee el archivo .txt y almacena en una lista cada una de las palabras separadas por ','.

    char string[5000], *list[200], *token;
    char * s = ",";
    int i;
    
    FILE *lista;
    lista = fopen("entrada.txt", "r");

    int MAX_FILE_SIZE = 1000;
    
    char * buffer = (char*)malloc(sizeof(char)*MAX_FILE_SIZE);
    
    fread(buffer, sizeof(char), MAX_FILE_SIZE, lista);

    list[0] = strtok(buffer, s);

    for (int i = 1;; i++){
        list[i] = strtok(NULL, s);
        if (list[i] == NULL) {
        break;
        }
    }

fclose(lista);

printf(list[1]); 
printf(list[0]);

}   