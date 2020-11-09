#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char identificador[30];
  char tipo[30];
  //void* valor;
} variable;

typedef struct nodoVariable{
    variable info;
    struct nodoVariable* sig;
} nodoVariable;

typedef struct{
    char identificador[30];
    char tipo[30];
    nodoVariable* listaParametros;
} funcion;

typedef struct nodoFuncion{
    funcion info;
    struct nodoFuncion* sig;
} nodoFuncion;

typedef struct nodoError{
    char info[30];
    struct nodoError* sig;
}nodoError;


int control_tipos(char* palabra, char* tipo) {
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  if(!strcmp(tipo, "char") && !strcmp(palabra, "char")){
    return 1;
  }
  if(!strcmp(tipo, "char*") && !strcmp(palabra, "char*")){
    return 1;
  }
  if(!strcmp(tipo, "void*") || !strcmp(tipo, "char*") || !strcmp(tipo, "int*") && !strcmp(palabra, "void*")){
    return 1;
  }
  if((!strcmp(tipo, "const") || !strcmp(tipo, "volatile") || !strcmp(tipo, "typedef")) && (!strcmp(palabra, "int"))){
    return 1;
  }
  return 0;
}

nodoVariable* existe_variable(nodoVariable* lista, char nombre[30]){
    nodoVariable* aux = lista;
    while(aux){
        if(!strcmp(lista->info.identificador, nombre)){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

char* tipo_variable(nodoVariable* lista, char nombre[30], FILE* arcFinal){
  nodoVariable* variable = existe_variable(lista, nombre);
  if(variable == NULL){
    fprintf(arcFinal, "La variable %s no fue declarada", nombre);
    return "error";
  } 
  return variable->info.tipo;
}

nodoFuncion* existe_funcion(nodoFuncion* lista, char* nombre){
    nodoFuncion* aux = lista;
    while(aux != NULL){
        if(!strcmp(aux->info.identificador, nombre)){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

int agregar_variable(nodoVariable* lista, char* nombre, char* tipo){
    if(existe_variable(lista, nombre) != NULL){
        return 0;
    }
    nodoVariable* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info.identificador, nombre);
    strcpy(aux->info.tipo, tipo);
    aux->sig = NULL;
    return 1;
}

int agregar_funcion(nodoFuncion* lista, char* nombre, char* tipo, nodoVariable* listaParametros){
    nodoFuncion* aux = lista;
    while(aux != NULL){
        aux = aux->sig;
    }
    aux = malloc(sizeof(*aux));
    strcpy(aux->info.identificador, nombre);
    strcpy(aux->info.tipo, tipo);
    aux->info.listaParametros = listaParametros;
    aux->sig = NULL;
}

void gestionar_identificador(nodoFuncion* listaFunciones, nodoVariable* listaVariables, char* nombre, char* tipo, int modo, nodoVariable* listaParametros, FILE* archivoFinal){
  switch(modo){
    case 0:
      if(!agregar_variable(listaVariables, nombre, tipo)){
        fprintf(archivoFinal, "Doble declaración de la variable: %s", nombre);
      }
      break;
    case 1:;
      nodoFuncion* aux = existe_funcion(listaFunciones, nombre);
      if(aux == NULL){
        agregar_funcion(listaFunciones, nombre, tipo, listaParametros);
      } else {
        parametros_contra_funcion(aux, listaParametros, archivoFinal);           
      }
      break;
  }
}

int parametros_contra_funcion(nodoFuncion* funcion, nodoVariable* listaParametros, FILE* archivoFinal){
  nodoVariable* auxLista = funcion->info.listaParametros;
  nodoVariable* auxParam = listaParametros;
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

void vaciar_parametros(nodoVariable* listaParametros){
  nodoVariable* aux;
  while(listaParametros != NULL){
    aux = listaParametros;
    listaParametros = listaParametros->sig;
    free(aux);
  }
}

//Esto es nefasto y super no performante, Para mi hay que rever la gramaica y simplificar
void pasar_a_lista_parametros(nodoVariable* listaParametros, nodoVariable* listavariables, int cantidad){
  nodoVariable* aux = listavariables;
  while(aux->sig != NULL){
    aux = aux->sig;
  }
  strcpy(listaParametros->info.identificador, aux->info.identificador);
  strcpy(listaParametros->info.tipo, aux->info.tipo);
  listaParametros->sig = NULL;
  free(aux);
  nodoVariable* auxParam = listaParametros->sig;
  cantidad--;
  while(cantidad != 0){
    aux = listavariables;
    while(aux->sig != NULL){
      aux = aux->sig;
    }
    strcpy(auxParam->info.identificador, aux->info.identificador);
    strcpy(auxParam->info.tipo, aux->info.tipo);
    auxParam->sig = NULL;
    auxParam = auxParam->sig;
    free(aux);
  }
}

void imprimir_variables(nodoVariable* lista, FILE* archivoFinal){
  nodoVariable* aux;
  while(lista){
    fprintf(archivoFinal, "Identificador: %s\t Tipo: %s\n", lista->info.identificador, lista->info.tipo);
    aux = lista;
    lista = lista->sig;
    free(aux);
  }
}

void imprimir_lista_variables(nodoVariable* lista, FILE* archivoFinal){
  fprintf(archivoFinal, "---------------------------------- VARIABLES ----------------------------------\n");
  imprimir_variables(lista, archivoFinal);
}

void imprimir_funciones(nodoFuncion* lista, FILE* archivoFinal){
  nodoFuncion* aux;
  fprintf(archivoFinal, "---------------------------------- FUNCIONES ----------------------------------\n");
  while(lista){
    fprintf(archivoFinal, "IDENTIFICADOR: %s\n Tipo Retorno: %s\n Parametros:\n", lista->info.identificador, lista->info.tipo);
    imprimir_variables(lista->info.listaParametros, archivoFinal);
    aux = lista;
    lista = lista->sig;
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
    free(aux);
  }
}








/*
//remover y copiarla en la ista de parametros
ESPECIFICADOR_TIPO

/// IDEA DANI (que tubo gracias al dibujito magnifico de Sol);
        // Copiar todas las variables de parametros a la lnodoFuncion* listaFunciones = NULL;


typedef struct nodoErrorLexico{
    char info[30];
    struct nodoError* sgt;
}nodoErrorLexico;

especificadorTipo: ESPECIFICADOR_TIPO {{strcpy(tipo, $<cadena>1)} fprintf(archivoFinal, "se encontro el tipo de dato %s \n", $<cadena>1);}
  | especificadorStructOUnion
  | especificadorEnum
;


especificadorStructOUnion: structOUnion identificadorOP '{' listaDeclaracionesStruct '}'
  | structOUnion IDENTIFICADOR {strcpy(tipo, $<cadena>2)}
;

identificadorOP: 
  | IDENTIFICADOR {strcpy(tipo, $<cadena>1)}
;

especificadorClaseAlmacenamiento: ESPECIFICADOR_ALMACENAMIENTO {if(tipo[0]== '\0'){strcpy(tipo, $<cadena>1)}}

declaradorDirecto: IDENTIFICADOR {{} fprintf(archivoFinal,"se encontro declaradorDirecto %s \n", $<cadena>1);}
  | '(' decla ')'
  | declaradorDirecto '[' expConstanteOP ']'
  | declaradorDirecto '(' listaTiposParametros ')' {fprintf(archivoFinal,"se encontró una firma de función")}
  | declaradorDirecto '(' listaIdentificadoresOP ')'
	| error {flag_error=1;fprintf(archivoFinal,"error xd \n");}
;

calificadorTipo: CONST {if(tipo[0]== '\0'){strcpy(tipo, $<cadena>1)}}
  | VOLATILE {if(tipo[0]== '\0'){strcpy(tipo, $<cadena>1)}}
;

////  TP4.h
*/
