#include "common.h"

// pensez à retirer l'espace avant les arobases

/*@ axiomatic Count {
    logic integer count(int * t, integer size, integer val) 
        reads t[0 .. size - 1];

    axiom CountEmpty: 
        \forall int * t, integer start, size, val; start >= size ==> 
            count(t, size, val) == 0;

    axiom CountRecMatch:
        \forall int * t, integer end, val;
            0 <= end ==> t[end] == val ==> count(t, end + 1, val) == count(t, end, val) + 1;

    axiom CountRecMiss:
        \forall int * t, integer end, val;
            0 <= end ==> t[end] != val ==> count(t, end + 1, val) == count(t, end, val);
}
*/

/*@ requires \valid(t + (0 .. size - 1));
    ensures \result == count(t, size, val);
    assigns \nothing;
*/
unsigned int count(int * t, unsigned int size, int val) {
    unsigned int result = 0;
    unsigned int i = 0;

    /*@ loop invariant 0 <= i <= size;
        loop invariant count(t, i, val) == result;
        loop assigns i, result;
        loop variant size - i;
    */
    while(i < size) {
        if(t[i] == val) result++;
        i++;
    }
    return result;
}