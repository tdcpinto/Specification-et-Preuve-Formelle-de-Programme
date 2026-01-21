#include "common.h"

typedef enum {
    MAX,
    MIN
} Action;

// [1, 2, 3] -> min = 1
/*@ predicate min_predicate(integer min, int * tab, integer size) = 
        \forall integer i; 0 <= i < size ==> min <= tab[i];
*/

/*@ predicate max_predicate(integer max, int * tab, integer size) = 
        \forall integer i; 0 <= i < size ==> max >= tab[i];
*/

/*@ predicate in_array(integer val, int * tab, integer size) = 
        \exists integer i; 0 <= i < size && val == tab[i];
*/

/*@ requires size > 0 && \valid(tab + (0 .. size - 1)) && (a == MAX || a == MIN);
    behavior min:
        assumes a == MIN;
        ensures min_predicate(\result, tab, size) && in_array(\result, tab, size);
    behavior max:
        assumes a == MAX;
        ensures max_predicate(\result, tab, size) && in_array(\result, tab, size);
    complete behaviors min, max;
    disjoint behaviors min, max;
*/
int compute(Action a, int * tab, unsigned int size) {
    int result = tab[0];
    unsigned int i = 1;
    /*@ loop invariant 0 <= i <= size;
        loop invariant 
            a == MIN ==> 
                (min_predicate(result, tab, i) && in_array(result, tab, i));
        loop invariant 
            a == MAX ==> 
                (max_predicate(result, tab, i) && in_array(result, tab, i));
        loop assigns result, i;
        
    */
    while(i < size) {
        if(a == MIN && result > tab[i]) result = tab[i];
        if(a == MAX && result < tab[i]) result = tab[i];
        i++;
    }
    return result;
}