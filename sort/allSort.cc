#include <iostream>

using namespace std;

const int DIM = 10;

void swap(int &a, int &b);
void printarray(int a[]);

void bubblesort(int array[]);
void quicksort(int array[]);
void quicksort_rec(int array[], int primo, int ultimo);


int main(int argc, char const *argv[]) {
  int a[] = {4, 1, 3, 6, 10, 7, 8, 5, 9, 2};

  printarray(a);

  bubblesort(a);
  //quicksort(a);
  printarray(a);

  return 0;
}
/* ------ UTILITY FUNCTIONS ------ */
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void printarray(int array[]) {
   for (int i=0; i<DIM; i++)
     cout << array[i] << " ";
   cout << endl;
 }

/* ------ SORTING FUNCTIONS ------ */
void bubblesort(int array[]) {
  for (int j=DIM-1; j>0; j--) {
     for (int i=0; i<j; i++) {
      if (array[i] > array[i+1])
        swap(array[i], array[i+1]);
    }
  }
}

void quicksort(int array[]) {
  quicksort_rec(array, 0, DIM-1);
}

void quicksort_rec(int array[], int primo, int ultimo) {
  if (primo < ultimo) {
    int p = primo;
    int u = ultimo;
    int pivot = array[ultimo];

    do {
      while (p < u && array[p] <= pivot)
        p++;
      while (u > p && array[u] >= pivot)
        u--;

      if (p < u)
        swap(array[p], array[u]);

    } while (p < u);

    swap(array[p], array[ultimo]);

    quicksort_rec(array, primo, p-1);
    quicksort_rec(array, p+1, ultimo);
  }
}
