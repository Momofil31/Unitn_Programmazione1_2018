#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione shift
int * shift(int v[], int n, int j);
void shift_rec(int v[], int nuovoV[], int n, int j, int indice);

int main(){
  int J = 0;
  const int N = 15;

  int vector[] = {2, 17, 44, 202, 5, 13, 26, 7, 9, 131, 51, 79, 88, 96, 32};

  cout << "Array iniziale: ";
  for(int i=0; i<N; i++) {
    cout << vector[i] << " ";
  }
  cout << endl;

  cout << "Numero spostamenti a sinistra: ";
  cin >> J;

  int* new_vect = shift(vector, N, J);

  cout << "Nuovo array: ";
  for(int i=0; i<N; i++) {
    cout << new_vect[i] << " ";
  }
  cout << endl;

  delete[] new_vect;

  return 0;
}

// Inserire qui sotto la definizione della funzione shift
int * shift(int v[], int n, int j) {
  //alloco nuovo vettore dinamico
  int * newV = new int[n];

  //chiamata alla funzione ricorsiva
  shift_rec(v, newV, n, j, 0);

  return newV;
}

void shift_rec(int v[], int nuovoV[], int n, int j, int indice) {
  if (indice < n) {
    if (indice+j < n)
      nuovoV[indice] = v[indice+j];
    else
      nuovoV[indice] = 0;

    //chiamata ricorsiva
    shift_rec(v, nuovoV, n, j, indice+1);
  }
}
