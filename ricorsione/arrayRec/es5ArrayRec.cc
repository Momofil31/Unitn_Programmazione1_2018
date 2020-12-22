#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

void leggiVettore(double a[], int& n);
void leggiVettoreRand(double a[], int& n);
void stampaVettore(const double a[], int& n);
void inserisciElemento(double a[], int& n, double& x, int& p);
void inserisciElementoRec(double a[], double& x, int& p, int max);


const int dim = 100;

int main(int argc, char const *argv[]) {
  int n1;
  double a[dim];
  double elemento;
  int posizione;

  leggiVettore(a, n1);
  stampaVettore(a, n1);

  cout << "Dammi un double: ";
  cin >> elemento;

  cout << "Dammi la posizione in cui inserirlo nel vettore: ";
  cin >> posizione;

  inserisciElemento(a, n1, elemento, posizione);

  stampaVettore(a, n1);

  return 0;
}

void inserisciElemento(double a[], int& n, double& x, int& p){
  inserisciElementoRec(a, x, p, n); // non decremento n di uno perchè aggiungere un elemento fa già di suo l'incremento della dimensione
  n++;
}

void inserisciElementoRec(double a[], double& x, int& p, int max){
  if(p == max){
    a[p] = x;
  } else {
    a[max] = a[max-1];
    inserisciElementoRec(a, x, p, max-1);
  }
}
void leggiVettore(double a[], int& n){
  cout << "Inserisci dimensione vettore: ";
  cin >> n;
  for(int i=0; i<n; i++){
    cout << "Inserisci l'elemento di posizione " << i << ": ";
    cin >> a[i];
  }
}
void leggiVettoreRand(double a[], int& n){
  srand (time(NULL));
  cout << "Inserisci dimensione vettore: ";
  cin >> n;
  for(int i=0; i<n; i++){
    a[i] = rand()%10;
  }
}
void stampaVettore(const double a[], int& n){
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
  }
}
