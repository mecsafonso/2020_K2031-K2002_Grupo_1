#include "TP4.h"


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
    fprintf(arcFinal, "La variable %s no fue declarada\n", nombre);
    return "error";
  } 
  return variable->info.tipo;
}

void agregar_parametro(nodoInfo** listaParametros, char tipo[]){
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

void agregar_error(nodoInfo* lista, char error[]){
    nodoInfo* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info, error);
    aux->sig = NULL;
}

void gestionar_identificador(nodo** listaVariables, char nombre[], char tipo[], FILE* archivoFinal){
    if(!agregar_variable(listaVariables, nombre, tipo)){
      fprintf(archivoFinal, "Doble declaración de la variable: %s \n", nombre);
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
        fprintf(archivoFinal, "La funcion %s no fue declarada\n", identificador);
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
      fprintf(archivoFinal, "La funcion %s esperaba una variable de tipo %s como parametro %d, pero recibio %s\n", funcion->info.identificador, auxLista->info, contador_parametros, auxParam->info);
      return 0;
    }
    auxLista = auxLista->sig;
    auxParam = auxParam->sig;
  }
  if(auxLista != NULL){
    fprintf(archivoFinal, "La funcion %s esperaba mas parametros de los recibidos\n", funcion->info.identificador); 
    return 0;
  } 
  if (auxParam != NULL){
    fprintf(archivoFinal, "La funcion %s recibio menos parametros de los esperados\n", funcion->info.identificador);     
  }
  return 1;
}

void imprimir_parametros(nodoInfo* lista, FILE* archivoFinal){
  nodoInfo* aux = lista;
  int i = 0;
  while(aux != NULL){
    fprintf(archivoFinal, "\t\t\tIdentificador N°: %d\t Tipo: %s\n", i, aux->info);
    aux = aux->sig;
    i++;
  }
}

void imprimir_lista_variables(nodo* lista, FILE* archivoFinal){
  fprintf(archivoFinal, "---------------------------------- VARIABLES ----------------------------------\n");
  nodo* aux = lista;
  while(aux != NULL){
    if(aux->info.es_funcion == 0){
      fprintf(archivoFinal, "Identificador: %s\t Tipo: %s\n", aux->info.identificador, aux->info.tipo);
    }
    aux = aux->sig;
  }
}

void imprimir_funciones(nodo* lista, FILE* archivoFinal){
  nodo* aux = lista;
  fprintf(archivoFinal, "---------------------------------- FUNCIONES ----------------------------------\n");
  while(aux != NULL){
    if(aux->info.es_funcion == 1){
      fprintf(archivoFinal, "IDENTIFICADOR: %s\n\t Tipo Retorno: %s\n\t Parametros:\n", aux->info.identificador, aux->info.tipo);
      imprimir_parametros(aux->info.listaParametros, archivoFinal);
    }    
    aux = aux->sig;
  }
}

void imprimir_errores(nodoInfo** lista, FILE* archivoFinal){
  nodoInfo* aux;
  fprintf(archivoFinal, "---------------------------------- ERRORES LEXICOS ----------------------------------\n");
  while(*lista){
    aux = (*lista);
    fprintf(archivoFinal, "%s\n", aux->info);
    (*lista) = aux->sig;
    free(aux->info);
    free(aux);
  }
}




