#include "common.h"

/*@ predicate valid_ptr(int * a, integer size) =
        \valid(a + (0 .. size));
*/

/*@ predicate in_bounds(integer x) =
        INT_MIN <= x <= INT_MAX;
*/

/*@ predicate sum_in_bounds(int * a, int * b, integer size) =
        \forall integer i; 0 <= i < size ==> in_bounds(a[i] + b[i]);
*/

/*@ predicate is_sum{L, M}(int * a, int * b, integer size) =
        \forall integer i; 0 <= i < size ==> 
            \at(a[i], M) == \at(a[i], L) + \at(b[i], L);
*/

/*@ predicate unchanged{L, M}(int * a, integer start, integer size) =
        \forall integer i; start <= i < size ==>
            \at(a[i], L) == \at(a[i], M);
*/

/*@ requires valid_ptr(a, size) && valid_ptr(b, size);
    requires \separated(a + (0 .. size - 1), b + (0 .. size - 1));
    requires sum_in_bounds(a, b, size);
    ensures is_sum{Pre, Post}(a, b, size);
*/
void compute(int* a, int* b, unsigned int size) {
  unsigned int i = 0;

  /*@ loop invariant 0 <= i <= size;
      loop invariant is_sum{Pre, Here}(a, b, i);
      loop invariant unchanged{Pre, Here}(a, i, size);
      loop assigns a[0 .. size - 1], i;
      loop variant size - i;
  */
  while(i < size) {
    a[i] = a[i] + b[i];
    i++;
  }
}