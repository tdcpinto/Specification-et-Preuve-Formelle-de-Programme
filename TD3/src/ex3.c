#include "common.h"

// pensez à retirer l'espace avant l'arobase
// vous pouvez réutiliser certains des prédicats 
// écrits dans l'exercice 2

/* @ predicate in_range(integer a, integer b, integer c) =
        un prédicat qui est vrai si 'c' est dans
        l'intervalle [a, b] 
*/

/* @ predicate valid_ptr(int * a, integer start, integer size) =
        un prédicat qui est valide si les cases du
        tableau 'a' sont valides entre start et size - 1
*/

/* @ predicate swapped{L, M}(int * a, int * b) = 
        un prédicat qui est vrai :
        - si la valeur de 'a'
        au moment 'M' est égal à la valeur de 'b' au
        moment 'L' ET
        - si la valeur de 'b'
        au moment 'M' est égal à la valeur de 'a' au
        moment 'L'

*/

/* @ predicate in_array(int * t, integer start, integer size, integer val) =
        un prédicat qui est vrai si il existe une valeur
        du tableau 't' entre les indices 'start' et 'size' 
        qui vaut 'val'
*/

/* @ predicate upper_bound(int * t, integer start, integer size, integer max) =
        un prédicat qui est vrai si la valeur 'max' est 
        plus grande que toutes les valeurs du tableau 't' 
        entre 'start' et 'size'
*/

/* @ predicate sorted(int * t, integer start, integer size) =
        un prédicat qui est vrai si le tableau 't' est 
        trié en ordre décroissant entre les index
        'start' et 'size'
*/

/* @ Une spécification qui est valide si :
     - les cases du tableau 'tab' sont valides entre
       'start' et 'size'
     - la slice du tableau choisie est strictement non vide
     Et qui certifie que :
     - la valeur de retour est un indice de la slice du tableau
       choisie
     - l'indice retourné correspond au maximum de la slice
       du tableau choisie
     - Aucune case du tableau n'est changées (peut se faire
       avec la clause 'assigns').
*/
unsigned int max_index(int *tab, unsigned int start, unsigned int size) {
    int max = tab[start];
    unsigned int max_index = start;
    unsigned int i = start + 1;

    /* @ Des invariants de boucle permettant d'inférer
         la postcondition.
    */
    while (i < size) {
        if (tab[i] > max) {
            max = tab[i];
            max_index = i;
        }
        i++;
    }
    return max_index;
}

/* @ Une spécification qui est valide si :
     - les pointeurs 'a' et 'b' sont valides
     Et qui certifie que :
     - les valeurs pointées par 'a' et 'b' sont échangées
       (et donc modifiées)
*/
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* @ Une spécification qui est valide si :
     - les cases du tableau 'tab' sont valides entre
       0 et size - 1
     Et qui certifie que :
     - le tableau est trié en ordre décroissant entre
       0 et size - 1
     - le tableau est potentiellement modifié
*/
void sort(int * tab, unsigned int size) {
    unsigned int i = 0;

    /* @ Décrivez ici les invariants de boucle nécessaires
         pour prouver la correction de cet algorithme.
         Indice : si vous considérez que le tableau est trié
         en ordre décroissant entre 0 et i - 1, vous ne dites
         rien sur le reste du tableau.
         En particulier, sans invariant supplémentaires,
         rien interdit que certaines valeurs
         de la partie non triée sont plus grandes que certaines
         valeurs de la partie triée (bien sûr l'algorithme
         étant correct, ce ne sera pas le cas, mais ça,
         Frama-C ne le sait pas).
    */
    while(i < size) {
        unsigned int index = max_index(tab, i, size);
        swap(&tab[i], &tab[index]);
        i++;
    }
}