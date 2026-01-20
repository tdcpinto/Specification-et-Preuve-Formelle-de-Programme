#include "common.h"

typedef enum {
    MAX,
    MIN
} Action;

// pensez à enlever l'espace avant l'arobase

/* @ predicate min_predicate(integer min, int * tab, integer size) = 
        un prédicat qui est vrai si la valeur 'min' est plus
        petite que toutes les valeurs du tableau
*/

/* @ predicate max_predicate(integer max, int * tab, integer size) = 
        un prédicat qui est vrai si la valeur 'max' est plus
        grande que toutes les valeurs du tableau
*/

/* @ Une spécification qui :
    - Donne des préconditions pour que le tableau contienne au moins un élément
    - Donne des postconditions pour que la valeur retournée soit le
      maximum du tableau si a vaut MAX, et le minimum si a vaut MIN
*/
int compute(Action a, int * tab, unsigned int size) {
    int result = tab[0];
    unsigned int i = 1;
    /* @ Des invariants de boucles qui permettent de prouver
         votre spécification.
    */
    while(i < size) {
        if(a == MIN && result > tab[i]) result = tab[i];
        if(a == MAX && result < tab[i]) result = tab[i];
        i++;
    }
    return result;
}