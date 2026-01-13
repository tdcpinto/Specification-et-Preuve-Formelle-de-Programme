#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

/*@ ensures x > y ==> \result == x && x <= y ==> \result == y;
 */
int max(int x, int y) {
    int res;
    if(x > y) {
        res = x;
    } else {
        res = y;
    }
    return y;
}

int main() {
    return max(1, 2);
}