#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

int mystery(int * tab, int size, int y) {
    int res = 0;
    int i = 0;

    while(i < size) {
        if(tab[i] == y) res = res + 1;
        i = i +1;
    }
    if(res >= 2) res = 1;
    else res = 0;
    return res;
}