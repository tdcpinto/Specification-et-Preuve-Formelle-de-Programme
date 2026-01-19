#include "common.h"

// la fonction fait la somme de deux tableaux d'entiers
// et stocke le résultat dans le premier tableau
void compute(int* a, int* b, unsigned int size) {
  unsigned int i = 0;
  while(i < size) {
    a[i] = a[i] + b[i];
    i++;
  }
}
