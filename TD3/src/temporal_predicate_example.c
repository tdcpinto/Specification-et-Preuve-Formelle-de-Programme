#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

/*@ predicate swapped{L, M}(int * a, int * b) =
        \at(*a, L) == \at(*b, M) &&
        \at(*b, L) == \at(*a, M);
*/

/*@ requires \valid(a) && \valid(b);
    ensures swapped{Pre, Post}(a, b);
*/
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}