#include <iostream>
#include <cmath>

using namespace std;

void norma(const double a[]);
const int dim = 3;

int main(int argc, char const *argv[]) {
  double a[dim] = {1, 2, 3};
  norma(a);
  return 0;
}

void norma(const double a[]){
  double prodScalare = 0;
  double norma;
  for (int i = 0; i < dim; i++) {
    prodScalare += a[i]*a[i];
  }
  norma = sqrt(prodScalare);
  cout << "La norma e': " << norma << endl;
}
