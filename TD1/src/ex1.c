#include <limits.h>

#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

unsigned int mod(unsigned int a, unsigned int b) {
    return a % (b + 1);
}

unsigned int mod2(unsigned int a, unsigned int b) {
    if(b == UINT_MAX) {
        return a;
    }
    return a % (b + 1);
}

int main() {
    mod(5, 2);
    mod2(5, 2);
    return 0;
}