#include "common.h"

// pensez à retirer l'espace avant l'arobase
// vous pouvez réutiliser certains des prédicats 
// écrits dans l'exercice 2

/*@ predicate in_range(integer a, integer b, integer c) =
        a <= c <= b;
*/

/*@ predicate valid_ptr(int * a, integer start, integer size) =
        \valid(a + (0 .. size - 1));
*/

/*@ predicate swapped{L, M}(int * a, int * b) = 
        \at(*a, L) == \at(*b, M) &&
        \at(*b, L) == \at(*a, M);
*/

/*@ predicate in_array(int * t, integer start, integer size, integer val) =
        \exists integer i; start <= i < size && t[i] == val;
*/

/*@ predicate upper_bound(int * t, integer start, integer size, integer max) =
        \forall integer i; start <= i < size ==> max >= t[i];
*/

/*@ predicate sorted(int * t, integer start, integer size) =
        \forall integer i; start <= i < size - 1 ==> t[i] >= t[i + 1];
*/

/*@ requires valid_ptr(tab, start, size);
    requires start < size;
    ensures in_range(start, size - 1, \result);
    ensures upper_bound(tab, start, size, tab[\result]);
    assigns \nothing;
*/
unsigned int max_index(int *tab, unsigned int start, unsigned int size) {
    int max = tab[start];
    unsigned int max_index = start;
    unsigned int i = start + 1;

    /*@ loop invariant in_range(start, size, i);
        loop invariant upper_bound(tab, start, i, max);
        loop invariant in_array(tab, start, i, max);
        loop invariant max == tab[max_index];
        loop invariant in_range(start, i - 1, max_index);
        loop assigns max, max_index, i;
        loop variant size - i;
    */
    while (i < size) {
        if (tab[i] > max) {
            max = tab[i];
            max_index = i;
        }
        i++;
    }
    return max_index;
}

/*@ requires \valid(a) && \valid(b);
    ensures swapped{Pre, Post}(a, b);
    assigns *a, *b;
*/
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*@ requires valid_ptr(tab, 0, size);
    ensures sorted(tab, 0, size);
    assigns tab[0 .. size - 1];
*/
void sort(int * tab, unsigned int size) {
    unsigned int i = 0;

    /*@ loop invariant in_range(0, size, i);
        loop invariant sorted(tab, 0, i);
        loop invariant \forall integer j; 0 <= j < i ==> upper_bound(tab, i, size, tab[j]);
        loop assigns tab[0 .. size - 1], i;
        loop variant size - i;
    */
    while(i < size) {
        unsigned int index = max_index(tab, i, size);
        swap(&tab[i], &tab[index]);
        i++;
    }
}