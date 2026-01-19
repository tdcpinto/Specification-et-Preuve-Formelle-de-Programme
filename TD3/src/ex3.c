#include "common.h"

unsigned int max_index(int *tab, unsigned int start, unsigned int size) {
    int max = tab[start];
    unsigned int max_index = start;
    unsigned int i = start;

    while (i < size) {
        if (tab[i] > max) {
            max = tab[i];
            max_index = i;
        }
        i++;
    }
    return max_index;
}

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int * tab, unsigned int size) {
    unsigned int i = 0;
    while(i < size) {
        unsigned int index = max_index(tab, i, size);
        swap(&tab[i], &tab[index]);
        i++;
    }
}