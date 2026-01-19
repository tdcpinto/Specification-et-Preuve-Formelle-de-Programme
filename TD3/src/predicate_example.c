#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

/*@ predicate valid_div(integer a, integer b) =
        (a != INT_MIN || b != -1) && b != 0;
*/

/*@ requires valid_div(x, y);
    ensures \result == x / y;
*/
int div(int x, int y) {
    return x / y;
}