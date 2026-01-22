#include "common.h"

// pensez à retirer l'espace avant l'arobase
//
// Pour rappel un un tableau contient un palindrome
// si la lecture des éléments du début vers la fin
// est la même que la lecture des éléments de la fin
// vers le début. 
// Par exemple, les tableaux suivants
// contiennent des palindromes : 
// - [1, 2, 3, 2, 1],
// - [4, 5, 5, 4],
// - [6],
// - []
// Les tableaux suivants n'en contiennent pas :
// - [1, 2, 3],
// - [1, 2, 3, 4],
// - [1, 2]

/* @ predicate opposite_equals(int * t, integer i, integer size) =
        un prédicat qui est vrai si l'élément à l'indice
        i est égal à l'élément à l'indice size - i - 1
*/

/* @ predicate all_opposite_equals(int * t, integer size) =
        un prédicat qui est vrai si pour tout indice i
        entre 0 et size - 1, opposite_equals(t, i, size) est vrai
*/

/* @ Une spécification telle que :
    - le résultat est SUCCESS si le tableau 
      contient un palindrome
    - le résultat est FAIL sinon
*/
Status palindrome(int * t, unsigned int size) {
    Status result = SUCCESS;
    unsigned int i = 0;

    /* @ Des invariants de boucle qui permettent de prouver
         la postcondition de la fonction.
    */
    while(i < size) {
        if(t[i] != t[size - i - 1]) result = FAIL;
        i++;
    }

    return result;
}