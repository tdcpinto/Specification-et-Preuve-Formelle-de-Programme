#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

/*@ requires a == 0 || a != -1 || b != INT_MIN;
    ensures (a == 0 ==> \result == 1) && 
            (a != 0 ==> \result == b / a);
    assigns \nothing;
 */
int div(int a, int b) {
    int res = 0;
    if(a == 0) {
        res = 1;
    } else {
        res = b / a;
    }
    return res;
}

int main() {
    return div(1, 1);
}