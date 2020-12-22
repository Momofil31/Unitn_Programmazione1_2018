#include <stdlib.h>
#include <stdio.h>

void stampa_array(int array[], int dim);
void somma_array(int n1[], int n2[], int risultato[], int dim);
void somma_arrayRec(int n1[], int n2[], int risultato[], int dim, int indice);

const int SIZE = 10;

int main() {
  int ar1[] = {5, 9, 2, 7, 10, 15, 3, 8, 4, 12};
  int ar2[] = {6, 3, 21, 1, 17, 11, 24, 9, 8, 19};
  int ar3[SIZE];

  printf("Array1 = ");
  stampa_array(ar1, SIZE);
  printf("\n");
  printf("Array2 = ");
  stampa_array(ar2, SIZE);
  printf("\n");
  somma_array(ar1, ar2, ar3, SIZE);
  printf("Somma = ");
  stampa_array(ar3, SIZE);
  printf("\n");
  return 0;
}

void stampa_array(int array[], int dim) {
  int i;
  for (i = 0; i < dim; i++) {
    printf("%d ", array[i]);
  }
}
