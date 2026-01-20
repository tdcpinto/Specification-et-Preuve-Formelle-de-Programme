#include "common.h"

// pensez à enlever l'espace avant l'arobase

/* @ predicate valid_ptr(int * a, integer size) =
        un prédicat qui est vrai le tableau donné
        en argument est valide entre les indices 0 et size
*/

/* @ predicate in_bounds(integer x) =
        un prédicat qui est vrai si x est entre INT_MIN et INT_MAX
*/

/* @ predicate sum_in_bounds(int * a, int * b, integer size) =
        un prédicat qui est vrai si la somme a[i] et b[i]
        ne provoque pas d'overflow pour chaque index des
        tableaux
*/

/* @ predicate is_sum{L, M}(int * a, int * b, integer size) =
        un prédicat qui est vrai si la valeur de a[i] au moment
        M est égale à la somme de a[i] et b[i] au moment L
        pour tout index du tableau
*/

/* @ predicate unchanged{L, M}(int * a, integer start, integer size) =
        un prédicat qui est vrai si les valeurs de a, entre start et size
        n'ont pas changé entre les moments L et M
*/

/* @ Une spécification qui :
    - Donne des préconditions pour que les tableaux soient valides
      et séparés, et pour que la somme des éléments ne provoque
      pas d'overflow
    - Donne des postconditions pour que chaque élément de a soit
      la somme des éléments initiaux de a et b
*/
void compute(int* a, int* b, unsigned int size) {
  unsigned int i = 0;

  /* @ Des invariants de boucles qui permettent de prouver
       votre spécification.
       Un petit indice : votre boucle modifie le tableau
       'a', du point de vu de Frama-C, à chaque tour de boucle,
       n'importe quelle case du tableau peut changer.
       Pour la preuve de la postcondition, ça pose problème,
       d'où la nécessité du prédicat 'unchanged'.
  */
  while(i < size) {
    a[i] = a[i] + b[i];
    i++;
  }
}
