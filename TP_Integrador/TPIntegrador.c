#include "TPIntegrador.h"

//Funciones para agregar elementos en las distintas listas

void agregar_info(nodoInfo** listaParametros, char tipo[]){
  nodoInfo* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoInfo));
    strcpy((*listaParametros)->info, tipo);
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoInfo));
  strcpy(aux->sig->info, tipo);
  aux->sig->sig = NULL;
  return;
}

void agregar_validaciones_sintacticas(nodoError** listaParametros, int nroLinea , char* mensaje){
  agregar_nodo_error(listaParametros, mensaje, nroLinea);
}

void agregar_error_sintactico(nodoErroresSintacticos** listaParametros, int nroLinea){
  nodoErroresSintacticos* aux = (*listaParametros);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*listaParametros) = malloc(sizeof(nodoErroresSintacticos));
    (*listaParametros)->linea = nroLinea;
    (*listaParametros)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoErroresSintacticos));
  aux->sig->linea = nroLinea;
  aux->sig->sig = NULL;
  return;
}

void agregar_error_lexico(nodoError** lista, char* error, int nroLinea){
  agregar_nodo_error(lista, error, nroLinea);
}

void agregar_nodo_error(nodoError** lista, char* error, int nroLinea){
  nodoError* aux = (*lista);
  while(aux != NULL && aux->sig != NULL){
      aux = aux->sig;
  }
  if(aux == NULL){
    (*lista) = malloc(sizeof(nodoError));
    (*lista)->info = malloc(strlen(error)+1);
    strcpy((*lista)->info, error);
    (*lista)->linea = nroLinea;
    (*lista)->sig = NULL;
    return;
  }
  aux->sig = malloc(sizeof(nodoError));
  aux->sig->info = malloc(strlen(error)+1);
  strcpy(aux->sig->info, error);
  aux->sig->linea = nroLinea;
  aux->sig->sig = NULL;
  return;
}

int agregar_variable(nodo** lista, char nombre[], char tipo[]){
    if(existe_variable(*lista, nombre) != NULL){
        return 0;
    }
    nodo* aux = (*lista);
    while(aux != NULL && aux->sig != NULL){
        aux = aux->sig;
    }
    if(aux == NULL){
      (*lista) = malloc(sizeof(nodo));
      (*lista)->info.es_funcion = 0;
      (*lista)->info.listaParametros = NULL;
      strcpy((*lista)->info.identificador, nombre);
      strcpy((*lista)->info.tipo, tipo);
      (*lista)->sig = NULL;
      return 1;
    }
    aux->sig = malloc(sizeof(nodo));
    strcpy(aux->sig->info.identificador, nombre);
    strcpy(aux->sig->info.tipo, tipo);
    aux->sig->info.es_funcion = 0;
    aux->sig->info.listaParametros = NULL;
    aux->sig->sig = NULL;
    return 1;
}

void agregar_funcion(nodo** lista, char nombre[], char tipo[], nodoInfo* listaParametros){
    nodo* aux = (*lista);
    while(aux != NULL && aux->sig != NULL){
        aux = aux->sig;
    }
    if(aux == NULL){
      (*lista) = malloc(sizeof(nodo));
      (*lista)->info.es_funcion = 1;
      (*lista)->info.listaParametros = listaParametros;
      strcpy((*lista)->info.identificador, nombre);
      strcpy((*lista)->info.tipo, tipo);
      (*lista)->sig = NULL;
      return;
    }
    aux->sig = malloc(sizeof(nodo));
    strcpy(aux->sig->info.identificador, nombre);
    strcpy(aux->sig->info.tipo, tipo);
    aux->sig->info.es_funcion = 1;
    aux->sig->info.listaParametros = listaParametros;
    aux->sig->sig = NULL;
}

//Funciones para realizar multiples cosas

int control_tipos(char palabra[], char tipo[]) {
  if(!strcmp(palabra, tipo)){
    return 1;
  }
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float") || !strcmp(palabra, "char")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  if((!strcmp(tipo, "int*") || !strcmp(tipo, "float*")) && (!strcmp(palabra, "int*") || !strcmp(palabra, "float*"))){
    return 1;
  }
  if((!strcmp(tipo, "char*") || !strcmp(tipo, "int*") || !strcmp(tipo, "float*")) && (!strcmp(palabra, "void*"))){
    return 1;
  }
  if((!strcmp(palabra, "char*") || !strcmp(palabra, "int*") || !strcmp(palabra, "float*")) && (!strcmp(tipo, "void*"))){
    return 1;
  }
  if((!strcmp(tipo, "const") || !strcmp(tipo, "volatile") || !strcmp(tipo, "typedef") || !strcmp(tipo, "int")) && (!strcmp(palabra, "const") || !strcmp(palabra, "volatile") || !strcmp(palabra, "typedef") || !strcmp(palabra, "int"))){
    return 1;
  }
  return 0;
}

nodo* existe_variable(nodo* lista, char nombre[]){
    nodo* aux = lista;
    while(aux){
        if(!strcmp(aux->info.identificador, nombre)){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

char* tipo_variable(nodo* lista, char nombre[], FILE* arcFinal){
  nodo* variable = existe_variable(lista, nombre);
  if(variable == NULL){
    fprintf(arcFinal, "   ♦ La variable %s no fue declarada\n", nombre);
    return "error";
  } 
  return variable->info.tipo;
}


void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal){
    if(!agregar_variable(listaVariables, nombre, tipo)){
      fprintf(archivoFinal, "   ♦ Doble declaración de la variable: %s \n", nombre);
    }    
}

void gestionar_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal){
    nodo* aux = existe_variable(*lista, identificador);
    if(aux == NULL){
        agregar_funcion(lista, identificador, tipo, listaParametros);
    } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
    }
}

void sentencia_funcion(nodo** lista, nodoInfo* listaParametros, char identificador[], FILE* archivoFinal){
  nodo* aux = existe_variable(*lista, identificador);
    if(aux == NULL){
        fprintf(archivoFinal, "   ♦ La funcion %s no fue declarada\n", identificador);
    } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
    }
}

int parametros_contra_funcion(nodo* funcion, nodoInfo* listaParametros, FILE* archivoFinal){
  nodoInfo* auxLista = funcion->info.listaParametros;
  nodoInfo* auxParam = listaParametros;
  int contador_parametros = 0;
  while(auxParam != NULL && auxLista != NULL){
    if(!control_tipos(auxParam->info, auxLista->info)){
      fprintf(archivoFinal, "   ♦ La funcion %s esperaba una variable de tipo %s como parametro %d, pero recibio %s\n", funcion->info.identificador, auxLista->info, contador_parametros, auxParam->info);
      return 0;
    }
    auxLista = auxLista->sig;
    auxParam = auxParam->sig;
  }
  if(auxLista != NULL){
    fprintf(archivoFinal, "   ♦ La funcion %s esperaba mas parametros de los recibidos\n", funcion->info.identificador); 
    return 0;
  } 
  if (auxParam != NULL){
    fprintf(archivoFinal, "   ♦ La funcion %s recibio menos parametros de los esperados\n", funcion->info.identificador);     
  }
  return 1;
}

//Funciones para imprimir las distintas listas

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal){
  nodoInfo* aux = lista;
  int i = 0;
  while(aux != NULL){
    //fprintf(archivoFinal, "│                      │         │                                    │\n");
    fprintf(archivoFinal, "│                      │         │ Identificador N°: %d\t Tipo: %-7s│\n", i, aux->info);
    aux = aux->sig;
    i++;
  }
}

void imprimir_lista_variables(nodo* lista, FILE* archivoFinal){
                             
  fprintf(archivoFinal, "\n\n\n----------------------------- VARIABLES -------------------------------\n\n * Se encontraron las siguientes variables declaradas:\n\n");
  nodo* aux = lista;
    fprintf(archivoFinal, " _____________________________________________________________________ \n");
  fprintf(archivoFinal, "│                             VARIABLES                               │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│           Identificador             │              Tipo             │\n");
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n");
  fprintf(archivoFinal, "│                                     │                               │\n");

  while(aux != NULL){
    if(aux->info.es_funcion == 0){
      fprintf(archivoFinal, "│ %17s                   │%16s               │\n", aux->info.identificador, aux->info.tipo);
    }
    aux = aux->sig;
  }
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n\n");
}

void imprimir_funciones(nodo* lista, FILE* archivoFinal){
  nodo* aux = lista;       
  fprintf(archivoFinal, "\n\n----------------------------- FUNCIONES -------------------------------\n\n * Se encontraron las siguientes funciones declaradas:\n\n");
  fprintf(archivoFinal, " _____________________________________________________________________ \n");
  fprintf(archivoFinal, "│                              FUNCIONES                              │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│     Identificador    │  Tipo   │             Parámetros             │\n");
  fprintf(archivoFinal, "│______________________│_________│____________________________________│\n");
  while(aux != NULL){
    if(aux->info.es_funcion == 1){
      fprintf(archivoFinal, "│                      │         │                                    │\n");
      fprintf(archivoFinal, "│ %-21s│ %-8s│                                    │\n", aux->info.identificador, aux->info.tipo);
      imprimir_parametros(aux->info.listaParametros, archivoFinal);
      fprintf(archivoFinal, "│______________________│_________│____________________________________│\n");
    }    
    aux = aux->sig;
  }
}

void imprimir_validaciones_sintacticas(nodoError** lista, FILE* archivoFinal){
  fprintf(archivoFinal, "\n\n----------------------------- SENTENCIAS ------------------------------\n\n");
  fprintf(archivoFinal, " * Se encontraron las siguientes sentencias:");
  fprintf(archivoFinal, "\n\n _____________________________________________________________________\n");
  fprintf(archivoFinal, "│                             SENTENCIAS                              │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│               Tipo                  │       Número de Línea         │\n");
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n");
  fprintf(archivoFinal, "│                                     │                               │\n");
  imprimir_nodo_error(lista, archivoFinal);
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n\n");
}

void imprimir_errores_sintacticos(nodoErroresSintacticos** lista, FILE* archivoFinal){
  nodoErroresSintacticos* aux;
  fprintf(archivoFinal, "\n\n------------------------- ERRORES SINTÁCTICOS -------------------------\n\n * Se encontraron errores sintácticos en las siguientes lineas:");
  fprintf(archivoFinal, "\n\n _____________________________________________________________________\n");
  fprintf(archivoFinal, "│                          ERRORES SINTÁCTICOS                        │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│                            Número de Línea                          │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│                                                                     │\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "│ %35d                                 │\n", aux->linea);
    (*lista) = aux->sig;
    free(aux);
  }
  fprintf(archivoFinal, "│_____________________________________________________________________│\n\n");
}

void imprimir_errores(nodoError** lista, FILE* archivoFinal){
  fprintf(archivoFinal, "\n\n--------------------------- ERRORES LÉXICOS ---------------------------\n\n");
  fprintf(archivoFinal, " * Los siguientes caracteres no pudieron ser reconocidos:");
  fprintf(archivoFinal, "\n\n _____________________________________________________________________\n");
  fprintf(archivoFinal, "│                       CARACTERES NO RECONOCIDOS                     │\n");
  fprintf(archivoFinal, "│_____________________________________________________________________│\n");
  fprintf(archivoFinal, "│              CARACTER               │       Número de Línea         │\n");
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n");
  fprintf(archivoFinal, "│                                     │                               │\n");
  imprimir_nodo_error(lista, archivoFinal);
  fprintf(archivoFinal, "│_____________________________________│_______________________________│\n\n");
}

void imprimir_nodo_error(nodoError** lista, FILE* archivoFinal){
  nodoError* aux;
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "│ %-34s  │              %-16d │\n", aux->info, aux->linea);
    (*lista) = aux->sig;
    free(aux->info);
    free(aux);
  }
}

// Funciones para la converción de números en formato octal/hexadecimal a decimal (FLEX)

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
