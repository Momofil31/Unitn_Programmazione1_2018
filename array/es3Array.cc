#include <iostream>
#include <cmath>

using namespace std;

void normalizza(const double a[], double b[], int& n);
double norma(const double a[], int& n);

const int dim = 100;

int main() {
  int n = 3;
  double a[dim] = {1, 1, 1};
  double b[dim] = {};

  normalizza(a, b, n);
  return 0;
}

double norma(const double a[], int& n){
  double prodScalare = 0;
  double norma;
  for (int i = 0; i < n; i++) {
    prodScalare += a[i]*a[i];
  }
  norma = sqrt(prodScalare);
  return norma;
}

void normalizza(const double a[], double b[], int& n){
  double normale = norma(a, n);
  for (int i = 0; i < n; i++) {
    b[i] = a[i]/normale;
    cout << b[i] << " ";
  }
  cout << endl;
}
