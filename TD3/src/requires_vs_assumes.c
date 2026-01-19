#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

/*@ behavior A:
        requires y != 0 && (x != INT_MIN || y != -1);
        ensures \result == x / y;
    complete behaviors A;
*/
int div(int x, int y) {
    return x / y;
}

/*@ behavior A:
        assumes y != 0 && (x != INT_MIN || y != -1);
        ensures \result == x / y;
    complete behaviors A;
*/
int div_2(int x, int y) {
    return x / y;
}