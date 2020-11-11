#include "TP4.h"

int control_tipos(char palabra[], char tipo[]) {
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  if(!strcmp(tipo, "char") && !strcmp(palabra, "char")){
    return 1;
  }
  if(!strcmp(tipo, "char*") && !strcmp(palabra, "char*")){
    return 1;
  }
  if((!strcmp(tipo, "void*") || !strcmp(tipo, "char*") || !strcmp(tipo, "int*")) && (!strcmp(palabra, "void*"))){
    return 1;
  }
  if((!strcmp(tipo, "const") || !strcmp(tipo, "volatile") || !strcmp(tipo, "typedef")) && (!strcmp(palabra, "int"))){
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
    fprintf(arcFinal, "La variable %s no fue declarada", nombre);
    return "error";
  } 
  return variable->info.tipo;
}

int agregar_variable(nodo* lista, char nombre[], char tipo[]){
    if(existe_variable(lista, nombre) != NULL){
        return 0;
    }
    nodo* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info.identificador, nombre);
    strcpy(aux->info.tipo, tipo);
    aux->info.es_funcion = 0;
    aux->info.listaParametros = NULL;
    aux->sig = NULL;
    return 1;
}

int agregar_funcion(nodo* lista, char nombre[], char tipo[], nodo* listaParametros){
    nodo* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info.identificador, nombre);
    strcpy(aux->info.tipo, tipo);
    aux->info.es_funcion = 1;
    aux->info.listaParametros = listaParametros;
    aux->sig = NULL;
}

void agregar_error(nodoError* lista, char error[]){
    nodoError* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info, error);
    aux->sig = NULL;
}

void gestionar_identificador(nodo* listaVariables, char nombre[], char tipo[], FILE* archivoFinal){
    if(!agregar_variable(listaVariables, nombre, tipo)){
      fprintf(archivoFinal, "Doble declaración de la variable: %s", nombre);
    }    
}

void gestionar_funcion(nodo* lista, nodo* listaParametros, char identificador[], char tipo[], FILE* archivoFinal){
    nodo* aux = existe_funcion(lista, identificador);
    if(aux == NULL){
        agregar_funcion(lista, identificador, tipo, listaParametros);
    } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
    }
}

int parametros_contra_funcion(nodo* funcion, nodo* listaParametros, FILE* archivoFinal){
  nodo* auxLista = funcion->info.listaParametros;
  nodo* auxParam = listaParametros;
  int contador_parametros = 0;
  while(auxParam != NULL && auxLista != NULL){
    if(!control_tipos(auxParam->info.tipo, auxLista->info.tipo)){
      fprintf(archivoFinal, "La funcion %s esperaba una variable de tipo %s como parametro %d, pero recibio %s", funcion->info.identificador, auxLista->info.tipo, contador_parametros, auxParam->info.tipo);
      return 0;
    }
    auxLista = auxLista->sig;
    auxParam = auxParam->sig;
  }
  if(auxLista != NULL){
    fprintf(archivoFinal, "La funcion %s esperaba mas parametros de los recibidos", funcion->info.identificador); 
    return 0;
  } 
  if (auxParam != NULL){
    fprintf(archivoFinal, "La funcion %s recibio mas parametros de los esperados", funcion->info.identificador);     
  }
  return 1;
}

void vaciar_parametros(nodo* listaParametros){
  nodo* aux;
  while(listaParametros != NULL){
    aux = listaParametros;
    listaParametros = listaParametros->sig;
    free(aux->info.identificador);
    free(aux->info.tipo);
    free(aux);
  }
}

/*void eliminar_ultimo(nodoVariable* listavariables){
    nodoVariable* aux = listavariables;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    free(aux->info.identificador);
    free(aux->info.tipo);
    aux = NULL;
}*/
/*
void pasar_a_lista_parametros(nodoVariable* listaParametros, nodoVariable* listavariables, int cantidad){
  if(cantidad <= 0){
      return;
  }
  nodoVariable* aux = listavariables;
  while(aux->sig != NULL){
    aux = aux->sig;
  }
  strcpy(listaParametros->info.identificador, aux->info.identificador);
  strcpy(listaParametros->info.tipo, aux->info.tipo);
  free(aux->info.identificador);
  free(aux->info.tipo);
  free(aux);

  cantidad--;
  nodoVariable* auxParam = NULL;
  listaParametros->sig = auxParam; 
  while(cantidad > 0){
    auxParam = malloc(sizeof(*auxParam));
    aux = listavariables;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    strcpy(auxParam->info.identificador, aux->info.identificador);
    strcpy(auxParam->info.tipo, aux->info.tipo);
    auxParam->sig = NULL;
    auxParam = auxParam->sig;
    free(aux->info.identificador);
    free(aux->info.tipo);
    aux = NULL;
  }
}*/

void imprimir_parametros(nodo* lista, FILE* archivoFinal){
  nodo* aux;
  while(lista != NULL){
    fprintf(archivoFinal, "\t\t\tIdentificador: %s\t Tipo: %s\n", lista->info.identificador, lista->info.tipo);
    aux = lista;
    lista = lista->sig;
    free(aux->info.identificador);
    free(aux->info.tipo);
    free(aux);
  }
}

void imprimir_lista_variables(nodo* lista, FILE* archivoFinal){
  fprintf(archivoFinal, "---------------------------------- VARIABLES ----------------------------------\n");
  nodo* aux = lista;
  while(aux != NULL){
    if(aux->info.es_funcion == 0){
      fprintf(archivoFinal, "Identificador: %s\t Tipo: %s\n", lista->info.identificador, lista->info.tipo);
    }
    aux = lista->sig;
  }
}

void imprimir_funciones(nodo* lista, FILE* archivoFinal){
  nodo* aux;
  fprintf(archivoFinal, "---------------------------------- FUNCIONES ----------------------------------\n");
  while(lista){
    if(aux->info.es_funcion == 1){
      fprintf(archivoFinal, "IDENTIFICADOR: %s\n\t Tipo Retorno: %s\n\t Parametros:\n", lista->info.identificador, lista->info.tipo);
      imprimir_parametros(lista->info.listaParametros, archivoFinal);
    }    
    aux = lista;
    lista = lista->sig;
    free(aux->info.identificador);
    free(aux->info.tipo);
    free(aux);
  }
}

void imprimir_errores(nodoError* lista, FILE* archivoFinal){
  nodoError* aux;
  fprintf(archivoFinal, "---------------------------------- ERRORES LEXICOS ----------------------------------\n");
  while(lista){
    fprintf(archivoFinal, "%s\n", lista->info);
    aux = lista;
    lista = lista->sig;
    free(aux->info);
    free(aux);
  }
}