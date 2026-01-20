#include "common.h"

// pensez à retirer l'espace avant les arobases

/*@ axiomatic Count {
    logic integer count(int * t, integer start, integer size, integer val) 
        reads t[start .. size - 1];

    axiom CountEmpty: 
        un axiome qui compte le nombre d'occurrences d'une valeur dans un
        tableau vide

    axiom CountRecMatch:
        un axiome qui exprime le nombre d'occurrence entre 'start' et 'end'
        en fonction du nombre d'occurrence entre 'start' et 'end + 1', sachant
        que t[end] = val

    axiom CountRecMiss:
        similaire au précédent, mais avec t[end] != val
}
*/

/*@ Une spécification qui correspond à retourner le nombre
    d'occurrences de 'val' dans 't'.
*/
unsigned int count(int * t, unsigned int size, int val) {
    unsigned int result = 0;
    unsigned int i = 0;

    /* @ Des invariants de boucle qui permettent
         d'inférer la postcondition.
    */
    while(i < size) {
        if(t[i] == val) result++;
        i++;
    }
    return result;
}