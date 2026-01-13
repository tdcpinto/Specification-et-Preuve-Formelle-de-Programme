#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

int max(int x, int y) {
    int res;
    if(x > y) {
        res = x;
    } else {
        res = y;
    }
    return res;
}

int main() {
    return max(1, 2);
}