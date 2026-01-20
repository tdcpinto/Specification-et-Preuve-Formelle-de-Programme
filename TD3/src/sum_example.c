#include "common.h"

/*@ logic integer partial_sum(int * t, integer start, integer size) =
        start < size ? t[start] + partial_sum(t, start + 1, size) : 0; 
*/

/* @ axiomatic SumTab {
    logic integer partial_sum(int * t, integer start, integer size) reads t[start .. size - 1];

    axiom SumEmpty: 
        \forall int * t, integer start, size; start >= size ==> 
            partial_sum(t, start, size) == 0;

    axiom SumRec:
        \forall int * t, integer start, integer end; start <= end ==>
            partial_sum(t, start, end) + t[end] ==  partial_sum(t, start, end + 1);
}
*/

/*@ requires \valid(t + (0 .. size - 1));
    requires \forall integer i; 0 <= i <= size ==> 
        INT_MIN <= partial_sum(t, 0, i) <= INT_MAX;
    ensures \result == partial_sum(t, 0, size);
    assigns \nothing;
*/
int sum(int * t, unsigned int size) {
    int result = 0;
    unsigned int i = 0;

    /*@ loop invariant 0 <= i <= size;
        loop invariant result == partial_sum(t, 0, i);
        loop assigns i, result;
        loop variant size - i;
    */
    while(i < size) {
        result += t[i];
        i++;
    }
    return result;
}