#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif
/*@ 
    requires \valid(tab + (0 .. size-1)) && size > 0;
    ensures \result == 1 <==> (\forall integer i, j; 0 <= i < j < size ==> tab[i] <= tab[j]);
    assigns \nothing;
*/
int is_sorted(int * tab, unsigned int size) {
    // if(size <= 0) {
    //     return 1;
    // }
    unsigned int i = 1;
    int res = 1;
    /*@ loop invariant I1 : 1 <= i <= size;
        loop invariant I2 : res == 1 <==> 
            (\forall integer j, k; 0 <= j <= k < i ==> tab[j] <= tab[k]);
        loop assigns res, i;
    */
    while(i < size) {
        if(tab[i - 1] > tab[i]) {
            res = 0;
        }
        i++;
    }
    return res;
}

/*@ requires \valid(tab + (0 .. size - 1));
    ensures \result == 1 <==> (\forall integer i; 0 <= i < size - 1 ==> (tab[i] <= tab[i + 1]));
 */
int is_sorted_2(int * tab, unsigned int size) {
    // if(size <= 0) {
    //     return 1;
    // }
    unsigned int i = 1;
    int res = 1;
    /*@ loop invariant I1 : 1 <= i <= size || size == 0;
        loop invariant I2 : res == 1 <==> 
            ((\forall integer j; 0 <= j < i - 1 ==> tab[j] <= tab[j + 1]) || size == 0);
        loop assigns res, i;
    */
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