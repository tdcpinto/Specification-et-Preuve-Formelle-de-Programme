#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

/*@ requires size > 0 && size <= INT_MAX && \valid(tab + (0 .. size-1));
    ensures \result == 1 <==> (\exists integer i, j; 0 <= i < j < size && tab[i] == y && tab[j] == y);
    assigns \nothing;
 */
int mystery(int * tab, int size, int y) {
    int res = 0;
    int i = 0;

    /*@ loop invariant I1: 0 <= i <= size;
        loop invariant I2: res == 0 ==> !(\exists integer j; 0 <= j < i && tab[j] == y);
        loop invariant I3: res == 1 ==> ((\exists integer j; 0 <= j < i && tab[j] == y) && 
                                         !(\exists integer k, l; 0 <= k < l < i && tab[k] == y && tab[l] == y));
        loop invariant I4: res >= 2 ==> (\exists integer j, k; 0 <= j < k < i && tab[j] == y && tab[k] == y);
        loop invariant I5: 0 <= res <= i;
        loop assigns i, res;
        loop variant size - i;
     */
    while(i < size) {
        if(tab[i] == y) res = res + 1;
        i = i +1;
    }
    if(res >= 2) res = 1;
    else res = 0;
    return res;
}