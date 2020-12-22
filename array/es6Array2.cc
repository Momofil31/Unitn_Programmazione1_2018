#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void leggiVettore(int a[], int& n);
void leggiVettoreRand(int a[], int& n);
void stampaVettore(const int a[], int& n);
void eliminaElemento(int a[], int& d, int x);

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
void stampaVettore(const int a[], int& n){
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

void eliminaElemento(int a[], int& d, int x){
  int j=0, count=0;
  for (int i=0; i<d; i++){
    j=i;
    while (a[j] == x){
      count++;
      j++;
    }
    a[i] = a[i+count];
    count--;
    d -= count;
  }
  // d -= count;
}

void leggiVettoreRand(int a[], int& n){
  srand (time(NULL));
  cout << "Inserisci dimensione vettore: ";
  cin >> n;
  for(int i=0; i<n; i++){
    a[i] = rand()%10;
  }
}
