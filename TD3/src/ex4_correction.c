#include "common.h"

// pour la fonction fibonacci, 
// on considère que fibonacci(0) = 1,
// fibonacci(1) = 1
// fibonacci(2) = 2
// fibonacci(3) = 3
// fibonacci(4) = 5
// ...
// en gros on indexe la séquence à partir de 0

/*@ axiomatic Fibonacci {

    logic integer fibonacci(integer n);

    axiom FiboZero: fibonacci(0) == 1;

    axiom FiboOne: fibonacci(1) == 1;

    axiom FiboRec: \forall integer n; n > 1 ==> 
                        fibonacci(n) == fibonacci(n - 1) + fibonacci(n - 2);

}
*/

/*@ requires \forall integer i; i <= n ==> fibonacci(i) <= INT_MAX; 
    ensures \result == fibonacci(n);
    assigns \nothing;
*/
int fibonacci(unsigned int n) {
    if(n <= 1) return 1;
    unsigned int previous = 1;
    unsigned int result = 1;
    unsigned int i = 1;

    /*@ loop invariant 1 <= i <= n;
        loop invariant result == fibonacci(i);
        loop invariant previous == fibonacci(i - 1);
        loop assigns previous, result, i;
        loop variant n - i;
    */
    while(i < n) {
        unsigned int tmp = result;
        result = result + previous;
        previous = tmp;
        i++;
    }
    return result;
} 