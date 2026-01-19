#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

/*@ terminates \true; */
int sum(unsigned int n) {
    unsigned int res = 0;
    unsigned int i = 0;
    /*@ loop variant n - i; */
    while(i < n) {
        res += i;
        i++;
    }
    return res;
}