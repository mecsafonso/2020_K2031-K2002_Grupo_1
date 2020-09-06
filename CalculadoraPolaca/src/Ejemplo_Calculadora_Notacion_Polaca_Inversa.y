/* Calculadora de notacion polaca inversa */

%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
int yylex();
int yyerror (char *s);
%}

%token NUM

%% /* A continuacion las reglas gramaticales y las acciones */

input:    /* vacio */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\t %d\n", $1); }
;

exp:      NUM             { $$ = $1;         }
        | exp exp '+'     { $$ = $1 + $2;    }
        | exp exp '-'     { $$ = $1 - $2;    }
        | exp exp '*'     { $$ = $1 * $2;    }
        | exp exp '/'     { $$ = $1 / $2;    }
        | exp exp '^'     { $$ = pow ($1, $2); }

;
%%

int yyerror (char *s)  /* Llamada por yyparse ante un error */
{
  printf ("%s\n", s);
}

int main ()
{
  printf("Ingrese una expresion aritmetica en notación polaca inversa para resolver:\n");
  yyparse ();
}
