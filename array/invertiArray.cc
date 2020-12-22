#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void leggiVettore(int a[], int& n);
void stampaVettore(const int a[], int n);
void invertiArray(int a[], int& n);
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

void invertiArray(int a[], int& n){
  for(int i=0; i<n/2; i++){
    scambia(a[i], a[n-i-1]);
  }
}
