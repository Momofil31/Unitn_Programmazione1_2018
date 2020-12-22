#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void leggiVettore(int a[], int& n);
void leggiVettoreRand(int a[], int& n);
void stampaVettore(const int a[], int& n);
void eliminaElemento(int a[], int& d, int x);
void traslaIndietroRec(int a[], int primo, int ultimo);

const int dim = 10000;

int main(int argc, char const *argv[]) {
  int n;
  int a[dim];
  int elemento;

  leggiVettore(a, n);
  stampaVettore(a, n);

  cout << "Inserisci l'elemento da eliminare: ";
  cin >> elemento;

  eliminaElemento(a, n, elemento);

  stampaVettore(a, n);
  cout << "la nuova dimensione dell'array e': " << n << endl;
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
void leggiVettoreRand(int a[], int& n){
  srand (time(NULL));
  cout << "Inserisci dimensione vettore: ";
  cin >> n;
  for(int i=0; i<n; i++){
    a[i] = rand()%10;
  }
}
void stampaVettore(const int a[], int& n){
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}



void traslaIndietroRec(int a[], int primo, int ultimo){
  if(primo > ultimo){
    // cout << "Sono entrato nel caso base." << endl;
  } else {
    // cout << "sono entrato nel caso comune." << endl;
    a[primo] = a[primo+1];
    traslaIndietroRec(a, primo+1, ultimo);
  }
}

void eliminaElemento(int a[], int& d, int x){
  for(int i=0; i<d; i++){
    // cout << "entrato nel ciclo" << endl;
    if(a[i] == x){
      // cout << "prima di traslare";
      traslaIndietroRec(a, i, d);
      d--;
      i--;
    }
  }
}
