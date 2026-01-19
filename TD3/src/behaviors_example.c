#ifdef __FRAMAC__
#include "__fc_builtin.h"
#endif

#include <limits.h>

typedef enum {
    SUCCESS,
    FAIL
} Status;

typedef enum {
    ADD,
    SUB
} Action;

/*@ requires \valid(res);
    assigns *res;
    behavior add:
        assumes a == ADD;
        ensures (INT_MIN <= x + y <= INT_MAX ==> (*res == x + y && \result == SUCCESS)) &&
                ((x + y > INT_MAX || x + y < INT_MIN) ==> \result == FAIL);
    behavior sub:
        assumes a == SUB;
        ensures (INT_MAX >= x - y >= INT_MIN ==> (*res == x - y && \result == SUCCESS)) &&
                ((x - y < INT_MIN || x - y > INT_MAX) ==> \result == FAIL);
    behavior fail:
        assumes a != ADD && a != SUB;
        ensures \result == FAIL;
    complete behaviors add, sub, fail;
    disjoint behaviors add, sub, fail;
*/
Status perform_action(Action a, int x, int y, int * res) {
    switch(a) {
        case ADD: if((y >= 0 && x > INT_MAX - y) || (y <= 0 && x < INT_MIN - y)) return FAIL; 
                  else { *res = x + y; return SUCCESS; }
        case SUB: if((y >= 0 && x < INT_MIN + y) || (y <= 0 && x > INT_MAX + y)) return FAIL; 
                  else { *res = x - y; return SUCCESS; }
        default: return FAIL;
    }
    return FAIL;
}