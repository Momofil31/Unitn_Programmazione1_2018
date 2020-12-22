#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void leggiVettore(int a[], int& n);
void leggiVettoreRand(int a[], int& n);
void stampaVettore(const int a[], int n);
void mescolaArray(const int a[], const int b[], int c[], int& n);

const int dim = 10000;

int main() {
  int n;
  int a[dim];
  int b[dim];
  int c[dim*2];

  leggiVettore(a, n);
  stampaVettore(a, n);

  leggiVettore(b, n);
  stampaVettore(b, n);


  mescolaArray(a, b, c, n);
  stampaVettore(c, n*2);

  return 0;
}

void leggiVettore(int a[], int& n){
  cout << "Inserisci dimensione vettore: ";
  cin >> n;
  for(int i=0; i<n; i++){
    cout << "Inserisci l'elemento di posizione " << i << ": ";
    cin >> a[i];
  }
}
void stampaVettore(const int a[], int n){
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

void mescolaArray(const int a[], const int b[], int c[], int& n){
  int countA = 0;
  int countB = 0;
  for(int i=0; i<n*2; i++){
    if (i%2 == 0) {
      c[i] = a[countA];
      countA++;
    } else {
      c[i] = b[countB];
      countB++;
    }
  }
}
