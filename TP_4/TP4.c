#include "TP4.h"

// Definición de la función put

var* putvar(char const*name, var* ts){
    var* ptr = (var*)malloc (sizeof (var));
    ptr->name = (char*) malloc(strlen(name)+1);
    strcpy(ptr->name, name);
    strcpy(ptr->type, NULL);
    ptr->next = (struct var*) ts;
    ts = ptr;
    return ptr;
}


function* putfunc(char const*name, function* ts){
    function* ptr = (function*)malloc (sizeof (function));
    ptr->name = (char*) malloc(strlen(name)+1);
    strcpy(ptr->name, name);
    strcpy(ptr->return_type, NULL);
    ptr->use_times = 0;
    ptr->ts_var = NULL;
    ptr->next = (struct function*) ts;
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
