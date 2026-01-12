#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

/*@ requires x < INT_MAX;
    ensures \result == x + 1;
    assigns \nothing;
 */
int add_one(int x) {
    return x + 1;
}

/*@ requires y != 0 && (x != INT_MIN || y != -1);
    ensures \result == x / y;
    assigns \nothing;
 */
int div(int x, int y) {
    return x / y;
}

int main() {
    add_one(12);
    div(10, 2);
    return 0;
}