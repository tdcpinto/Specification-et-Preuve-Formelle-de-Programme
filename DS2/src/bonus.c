#include "common.h"

// pensez à retirer l'espace avant l'arobase

/*@ requires \valid(a) && \valid(b);
    ensures \old(*a) == *b && *a == \old(*b);
    assigns *a, *b;
*/
void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* @ axiomatic Count {
    logic integer count{L}(int * t, integer size, integer val) 
        reads t[0 .. size - 1];

    axiom CountEmpty{L}: 
        un axiome qui dit que le nombre d'occurrences
        d'une valeur dans un tableau vide est zéro

    axiom CountRecMatch{L}:
        un axiome qui dit que si le dernier élément
        du tableau est égal à la valeur recherchée,
        alors le nombre d'occurrences dans le tableau
        est égal au nombre d'occurrences dans le tableau
        sans le dernier élément, plus un

    axiom CountRecMiss{L}:
        Le converse de la propriété précédente lorsque
        le dernier élément du tableau n'est pas égal
        à la valeur recherchée
}
*/

/* @ predicate permutation{L1,L2}(int *a, integer n) =
      un prédicat qui est vrai si les tableaux a[0..n-1]
      dans les états L1 et L2 contiennent les mêmes
      éléments, éventuellement dans un ordre différent
      (= sont des permutations l'un de l'autre)
*/

/* @ predicate upper_bound(int * t, integer start, integer size, integer max) =
        un prédicat qui est vrai si tous les éléments
        entre les indices start et size - 1 sont
        inférieurs ou égaux à max
*/

/* @ Une spécification de cette fonction auxiliaire
    qui réalise un passage de l'algorithme de tri à bulles :
    - le tableau après l'appel est une permutation
      du tableau avant l'appel
    - le dernier élément du tableau est
      plus grand que tous les autres éléments du tableau
*/
void bubble_sort_aux(int * t, unsigned int n) {
    unsigned int i = 0;

    /* @ Des invariants permettant de prouver la spécification
         de la fonction bubble_sort_aux.
    */
    while(i < n) {
        if(t[i] > t[i + 1]) {
            swap(&t[i], &t[i + 1]);
        }
        i++;
    }
}

/* @ predicate sorted(int * t, integer start, integer size) =
        un prédicat qui est vrai si tous les éléments
        entre les indices start et size - 1 sont
        triés par ordre croissant
*/

/* @ Une spécification de la fonction de tri à bulles.
*/
void bubble_sort(int * t, unsigned int n) {
    unsigned int i = 0;
    /* @ Les invariants suivants permettant de prouver
         la spécification de la fonction bubble_sort.
    */
    while(i < n) {
        bubble_sort_aux(t, n - i - 1);
        i++;
    }
}