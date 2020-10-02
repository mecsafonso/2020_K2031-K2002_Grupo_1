#ifndef TP4_H_
#define TP4_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct var {
    char type[50];
    char name[50];
    struct var* next;
}var;
typedef struct function{
    char return_type[50];
    char name[50];
    var* ts_var;
    var* ts_errores;
    struct function* next;
}function;

var* putvar(char const*name, var* ts, char* tipo){
    var* ptr = (var*)malloc (sizeof (var));
    strcpy(ptr->name, name);
    strcpy(ptr->type, tipo);
    if(ts == NULL){
        ptr->next == NULL;
    } else {
        ptr->next = (struct var*) ts;
    }
    ts = ptr;
    return ptr;
}


function* putfunc(char const*name, function* ts, char* tipo){
    function* ptr = (function*)malloc (sizeof (function));
    strcpy(ptr->name, name);
    strcpy(ptr->return_type, tipo);
    ptr->ts_var = NULL;
    ptr->ts_errores = NULL;
    if (ts == NULL){
        ptr->next = NULL;
    } else {
        ptr->next = (struct function*) ts;
    }
    ts = ptr;
    return ptr;
}

// Definición de la función get

var* getvar(char const*name, var* ts){
    var* ptr;
    for (ptr = ts; ptr != (var*)0; ptr = (var*)ptr->next){
        if(strcmp (ptr->name, name) == 0){
            return ptr;
        }
    }
    return 0;
}


function* getfunc(char const*name, function* ts){
    function* ptr;
    for (ptr = ts; ptr != (function*)0; ptr = (function*)ptr->next){
        if(strcmp (ptr->name, name) == 0){
            return ptr;
        }
    }
    return 0;
}

int compatibleA(char palabra[], char tipo[]) {
  if((!strcmp(tipo, "int") || !strcmp(tipo, "float")) && (!strcmp(palabra, "int") || !strcmp(palabra, "float") || !strcmp(palabra, "char"))){
    return 1;
  }
  else if(!strcmp(tipo, "char") && !strcmp(palabra, "char")){
    return 1;
  }
  else if(!strcmp(tipo, "char*") && !strcmp(palabra, "char*")){
    return 1;
  }
  else return 0;
}

#endif //TP4_H_