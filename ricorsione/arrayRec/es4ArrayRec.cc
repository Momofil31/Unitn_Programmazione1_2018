#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

void leggiVettore(double a[], int& n);
void leggiVettoreRand(double a[], int& n);
void stampaVettore(const double a[], int& n);

double prodScalare(const double a[], const double b[], int &n);
double prodScalareRec(const double a[], const double b[], int min, int max);
bool isOrtogonali(const double a[], const double b[], int &n);

const int dim = 100;

int main(int argc, char const *argv[]) {
  int n1, n2;
  double a[dim];
  double b[dim];

  leggiVettore(a, n1);
  stampaVettore(a, n1);
  leggiVettore(b, n2);
  stampaVettore(b, n2);

  if(isOrtogonali(a, b, n1)){
    cout << "I due vettori sono ortogonali." << endl;
  } else {
    cout << "I due vettori non sono ortogonali." << endl;
  }


  return 0;
}

bool isOrtogonali(const double a[], const double b[], int &n){
  bool res = false;
  if (prodScalare(a, b, n) == 0)
    res = true;
  return res;
}

double prodScalare(const double a[], const double b[], int &n){
  double res = 0;
  res = prodScalareRec(a, b, 0, n-1);
  return res;
}

double prodScalareRec(const double a[], const double b[], int min, int max){
  double res;
  if(min>max){
    res = 0;
  } else {
    res = a[min]*b[min] + prodScalareRec(a, b, min+1, max);
  }
  return res;
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
