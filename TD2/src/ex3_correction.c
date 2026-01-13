#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

/*@ requires \valid(a) && \valid(b);
    ensures \old(*a) == *b && \old(*b) == *a;
    assigns *a, *b;
 */
void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 12;
    int y = 13;
    swap(&x, &y);
    return 0;
}