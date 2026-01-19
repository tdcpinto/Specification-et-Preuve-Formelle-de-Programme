#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

/*@ logic integer abs(integer x) =
        (x >= 0 ? x : -x);
*/

/*@ requires x != INT_MIN;
    ensures \result == abs(x);
*/
int abs(int x) {
    if(x >= 0) return x;
    return -x;
}