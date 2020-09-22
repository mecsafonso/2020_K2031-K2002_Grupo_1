#ifndef TP4_H_
#define TP4_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct var {
    char* type;
    char* name;
    struct var* next;
}var;
typedef struct function{
    char* return_type;
    char* name;
    int use_times;
    var* ts_var;
    struct function* next;
}function;

// Declaracion de las funciones para agregar valores a las tablas
var* putvar(char const* , var*);
function* putfunc(char const *, function*);

// Declaracion de las funciones para consultar valores a las tablas
function* getfunc(char const *, function*);
var* getvar(char const* , var*);


#endif //TP4_H_