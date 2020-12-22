#include <iostream>
#include <cmath>
using namespace std;

// #include "array.h" /* leggi, stampa, MAX_DIM */

const int MAX_DIM = 5;
void leggi(int array[], int dim) {
  cout << "inserire dimensione <= 5" << endl;
  cin >> dim;
  for (size_t i = 0; i < dim; i++) {
    cin >> array[i];
  }
}
void stampa(double array[], int dim) {
  for (size_t i = 0; i < dim; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

using namespace std;

// Inserire qui sotto le DICHIARAZIONI delle funzioni

double calcola_norma_ricorsivo(int array[], int dim);
double somma_quadrati(int array[], int dim, int indice);

double* normalizza(int array[], int dim);
void normalizza_rec(int array[], double newArray[], int dim, int indice, double &norma);

int main() {
  int array[MAX_DIM];
  int dim;

  leggi(array, dim);

  double* normalizzato = normalizza(array, dim);

  cout << "Array normalizzato: " << endl;
  stampa(normalizzato, dim);

  return 0;
}

// Inserire qui sotto le DEFINIZIONI delle funzioni
double calcola_norma_ricorsivo(int array[], int dim) {
  double res = 0;
  res = sqrt(somma_quadrati(array, dim, 0));
  return res;
}

double somma_quadrati(int array[], int dim, int indice){
  int res = 0;
  if (indice < dim) {
    res = array[indice]*array[indice] + somma_quadrati(array, dim, indice+1);
  }
  return res;
}

double* normalizza(int array[], int dim) {
  //alloco array dinamico
  double* newArray = new double [dim];
  double norma = calcola_norma_ricorsivo(array, dim);
  cout << "La norma e'" << norma << endl;
  normalizza_rec(array, newArray, dim, 0, norma);
  return newArray;
}

void normalizza_rec(int array[], double newArray[], int dim, int indice, double &norma) {
  if (indice < dim) {
    newArray[indice] = array[indice]/norma;
    normalizza_rec(array, newArray, dim, indice+1, norma);
  }
}
