#include <iostream>
using namespace std;

void leggiVettore(double a[], int& n);
void stampaVettore(const double a[], int& n);
void aggiungiElemento(double a[], int& d, double x, int i);

const int dim = 100;

int main(int argc, char const *argv[]) {
  int n;
  double a[dim];
  double elemento;
  int posizione;

  leggiVettore(a, n);

  cout << "Inserisci il nuovo elemento: ";
  cin >> elemento;
  cout << "Inserisci la sua posizione nell'array: ";
  cin >> posizione;

  aggiungiElemento(a, n, elemento, posizione);

  stampaVettore(a, n);
  cout << "la nuova dimensione dell'array e': " << n << endl;
  return 0;
}

void leggiVettore(double a[], int& n){
  cout << "Inserisci dimensione vettore: ";
  cin >> n;
  for(int i=0; i<n; i++){
    cout << "Inserisci l'elemento di posizione " << i << ": ";
    cin >> a[i];
  }
}
void stampaVettore(const double a[], int& n){
  for(int i=0; i<n; i++){
    cout << a[i] << " ";
  }
}

void aggiungiElemento(double a[], int& d, double x, int i){
  for (int j=d; j>i; j--){
    a[j] = a[j-1];
  }
  a[i] = x;
  d++;
}
