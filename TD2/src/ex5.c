#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

/*@ requires n >= 0 && n * (n + 1) / 2 <= INT_MAX;
    ensures \result == n * (n + 1) / 2;
    assigns \nothing;
*/
int sum(int n) {
    int res = 0;
    int i = 0;

    while(i <= n) {
        res += i;
        i += 1;
    }
    return res;
}

int main() {
    return sum(12);
}