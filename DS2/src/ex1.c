#include "common.h"

typedef enum {
    ADD, SUB, MULT
} Action;

// pensez à retirer l'espace avant l'arobase

/* @ Écrire une spécification qui couvre la totalité des cas
     d'exécution possible.
     Notamment :
     - Lorsque l'action est ADD, la fonction retourne x + y
     - Lorsque l'action est SUB, la fonction retourne x - y
     - Lorsque l'action est MULT, la fonction retourne x * y
     - Dans les autres cas, la fonction retourne 0 
*/
unsigned int compute(unsigned int x, unsigned int y, Action a) {
    unsigned int result = 0;
    if(a == ADD) {
        result = x + y;
    } else if(a == SUB) {
        result = x - y;
    } else if(a == MULT) {
        result = x * y;
    }
    return result;
}