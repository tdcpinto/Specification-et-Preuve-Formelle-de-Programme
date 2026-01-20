#include "common.h"

// pour la fonction fibonacci, 
// on considère que fibonacci(0) = 1,
// fibonacci(1) = 1
// fibonacci(2) = 2
// fibonacci(3) = 3
// fibonacci(4) = 5
// ...
// en gros on indexe la séquence à partir de 0

// pensez à retirer l'espace avant les arobases

/* @ axiomatic Fibonacci {

    logic integer fibonacci(integer n);

    axiom FiboZero: un axiome qui exprime la valeur de fibonacci(0)

    axiom FiboOne: un axiome qui exprime la valeur de fibonacci(1)

    axiom FiboRec: un axiome qui exprime fibonacci(i) en fonction
                   de fibonacci(i - 1) et fibonacci(i - 2)

}
*/

/* @ Une spécification qui est valide si :
     - pour tout i <= n, fibonacci(i) ne dépasse pas
       la valeur maximale d'un entier (INT_MAX)
     Et qui certifie que :
     - la valeur de retour est égale à fibonacci(n)
*/
int fibonacci(unsigned int n) {
    if(n <= 1) return 1;
    unsigned int previous = 1;
    unsigned int result = 1;
    unsigned int i = 1;

    /* @ Des invariants de boucles décrivant :
         - l'intervalle de i
         - la valeur exacte de 'result'
         - la valeur exacte de 'previous'
         - les variables modifiées et la variante de boucle
    */
    while(i < n) {
        unsigned int tmp = result;
        result = result + previous;
        previous = tmp;
        i++;
    }
    return result;
} 