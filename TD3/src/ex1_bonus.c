#include "common.h"

typedef enum {
    MAX,
    MIN
} Action;

int compute(Action a, int * tab, unsigned int size) {
    int result = tab[0];
    unsigned int i = 1;

    while(i < size) {
        if(a == MIN && result > tab[i]) result = tab[i];
        if(a == MAX && result < tab[i]) result = tab[i];
        i++;
    }

    if(a == MIN && result != INT_MIN) return result - 1;
    if(a == MAX && result != INT_MAX) return result + 1;
    return result;
}