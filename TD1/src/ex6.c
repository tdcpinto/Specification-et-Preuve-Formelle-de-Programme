#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

int is_sorted(int * tab, unsigned int size) {
    unsigned int i = 1;
    int res = 1;

    while(i < size) {
        if(tab[i - 1] > tab[i]) {
            res = 0;
        }
        i++;
    }
    return res;
}

int main() {
    int tab[8] = {1, 5, 45, 85, 777, 7777, 10000, 10001};
    return is_sorted(tab, 8);
}