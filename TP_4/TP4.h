#ifndef TP4_H_
#define TP4_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYP_VAR 0
#define TYP_FNCT 1

typedef double (*func_t) (double);

//Definición de la estructura de los nodos de la TS, la denominamos symrec.

typedef struct symrec
{
  char *name;
  int type;   
  union
  {
    double var;    
    func_t fnctptr;
  } value;
  struct symrec *next;
} symrec;

//Declaración de la variable sym_table que apunta a la TS
//Se utiliza para exponer variables pertenecientes a un archivo a uno o varios archivos adicionales. 

extern symrec *sym_table;

//Declaración de la función putsym para agregar símbolo a la TS

symrec *putsym (char const *, int);

//Declaración de la función getsym para tomar un símbolo de la TS

symrec *getsym (char const *);

#endif //TP4_H_