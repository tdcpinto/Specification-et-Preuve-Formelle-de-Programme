#include "common.h"

// pensez à retirer l'espace avant l'arobase

// Dans cet exercice, on aura souvent besoin de la notation
// \at(expr, L) qui désigne la valeur de expr dans l'état L
// (par exemple: \at(size, Pre) est la valeur de size au début 
// de la fonction)

// Un tableau est considéré comme décalé vers la gauche (shifted left)
// si chaque élément à l'indice i _après le décalage_
// est égal à l'élément à l'indice i + 1 _avant le décalage_.
// Par exemple, le tableau si 't' est égal à [1, 2, 3, 4, 5] avant
// le décalage, alors après un décalage
// le tableau 't' sera égal à [2, 3, 4, 5, 5].
//
// Notez que le dernier élément du tableau reste inchangé
// après un décalage vers la gauche (il est dupliqué).
// Ce n'est pas 'grave', dans la mesure ou généralement
// après un décalage, on réduit la taille logique du tableau
// de 1 pour 'oublier' le dernier élément

/* @ predicate has_been_shifted{L, M}(int * t, integer start, integer size) =
        un prédicat qui est vrai si tous les éléments
        entre les indices start et size - 1 ont été décalés
        d'une position vers la gauche entre les états L et M
*/

/* @ predicate unchanged{L, M}(int * t, integer start, integer size) =
        un prédicat qui est vrai si tous les éléments
        entre les indices start et size - 1 sont inchangés
        entre les états L et M
*/

/* @ Une spécification qui décrit l'effet de la fonction
    shift_left sur le tableau t à partir de l'indice start
*/
void shift_left(int * t, unsigned int start, unsigned int size) {

    /* @ Les invariants de boucle suivants :
        - start est toujours entre sa valeur au début de la fonction et size
        - tous les éléments entre la valeur de start au début de la fonction 
          et la valeur actuelle de start ont été décalés d'une position vers la gauche
        - tous les éléments à partir de la valeur 
          actuelle de start n'ont pas été modifiés
    */
    while(start < size - 1) {
        t[start] = t[start + 1];
        start++;
    }
}

/* @ not_in_array(t, size, val) =
        un prédicat qui est vrai si val n'est pas présente
        dans le tableau t de taille size
*/

/* @ Une spécification de la fonction delete_val
    qui supprime toutes les occurrences de val dans le tableau t
    et retourne la nouvelle taille du tableau 
*/
unsigned int delete_val(int * t, unsigned int size, int val) {
    unsigned int i = 0;

    /* @ Les invariants qui permettent de prouver votre
         spécification.
    */
    while(i < size) {
        if(t[i] == val) {
            shift_left(t, i, size);
            size--;
        } else {
            i++;
        }
    }
    return size;
}