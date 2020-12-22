#include <iostream>

using namespace std;

// Inserire qui le DICHIARAZIONI delle funzioni
int somma_prodotto_incrociato(int primo[], int secondo[], int dim);
int somma_prodotto_incrociato_rec(int primo[], int secondo[], int dim, int indice);

int main() {
  int primo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int secondo[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
  cout << "La somma dei prodotti incrociati dei due array e’ " <<
  somma_prodotto_incrociato(primo, secondo, 10) << endl;
  return 0;
}

// Inserire qui le DEFINIZIONI delle funzioni

int somma_prodotto_incrociato(int primo[], int secondo[], int dim) {
  return somma_prodotto_incrociato_rec(primo, secondo, dim, 0);
}

int somma_prodotto_incrociato_rec(int primo[], int secondo[], int dim, int indice) {
  int res;
  //caso base
  if (indice == dim-1) {
    res = primo[indice] * secondo[dim-1-indice];
  } else {
    //sommo il prodotto dell'elemento considerato in questa chiamata
    //al risultato della chiamata con indice successivo
    res = primo[indice] * secondo[dim-1-indice] + somma_prodotto_incrociato_rec(primo, secondo, dim, indice+1);
  }
  return res;
}
