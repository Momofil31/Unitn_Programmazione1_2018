#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void leggiVettore(int a[], int& n);
void leggiVettoreRand(int a[], int& n);
void stampaVettore(const int a[], int& n);
void stampaVettore(const long a[], int& n);
void quadratoArray(const int a[], long b[], int& n);

const int dim = 10000;

int main(int argc, char const *argv[]) {
  int n;
  int a[dim];
  long b[dim];

  leggiVettore(a, n);
  stampaVettore(a, n);

  quadratoArray(a, b, n);
  stampaVettore(b, n);

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
void stampaVettore(const int a[], int& n){
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
void stampaVettore(const long a[], int& n){
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

void quadratoArray(const int a[], long b[], int& n){
  for (int i = 0; i < n; i++) {
    b[i] = a[i]*a[i];
  }
}
