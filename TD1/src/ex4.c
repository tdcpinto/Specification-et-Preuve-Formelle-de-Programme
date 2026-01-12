#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

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