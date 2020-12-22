#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void leggiVettore(int a[], int& n);
void stampaVettore(const int a[], int n);
void invertiArray(int a[], int& n);
void invertiArrayRec(int a[], int dim, int offset);
void scambia(int& a, int& b);

const int dim = 10000;

int main() {
  int n;
  int a[dim];

  leggiVettore(a, n);
  stampaVettore(a, n);
  invertiArray(a, n);

  stampaVettore(a, n);


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

void scambia(int& a, int& b){
  int t;
  t=a;
  a=b;
  b=t;
}

void invertiArrayRec(int a[], int dim, int offset){
  if (dim >= 2) {
    scambia(a[offset], a[offset - dim - 1]);
    invertiArrayRec(a, offset + 1, dim -2);
  }
}

void invertiArray(int a[], int& n){
  invertiArrayRec(a, n, 0);
}
