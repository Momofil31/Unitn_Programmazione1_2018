#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int dim = 100;

void leggiVettore(int a[], int& n);
void leggiVettoreRand(int a[], int& n);
void stampaVettore(const int a[], int& n);
int sommaElementiWrapper(const int a[], int& n);
int sommaElementi(const int a[], int min, int max);


int main(int argc, char const *argv[]) {
  int n;
  int a[dim];
  int somma;

  leggiVettore(a, n);
  stampaVettore(a, n);

  somma = sommaElementiWrapper(a, n);

  cout << "La somma ricorsiva degli elementi dell'array e': " << somma << endl;
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

int sommaElementiWrapper(const int a[], int& n){
  int res;
  res = sommaElementi(a, 0, n-1);
  return res;
}

int sommaElementi(const int a[], int min, int max){
  int res;
  if (min > max)
    res = 0;
  else
    res = a[min]+sommaElementi(a, min+1, max);
  return  res;
}
