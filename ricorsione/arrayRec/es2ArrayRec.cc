#include <iostream>
#include <cmath>
using namespace std;

double prodScalare(const double a[], const double b[], int &n);
double prodScalareRec(const double a[], const double b[], int min, int max);
double norma(const double a[], int &n);

const int dim = 100;

int main(int argc, char const *argv[]) {
  int n=3;
  double a[dim] = {1, 2, 3};
  double res;
  res = norma(a, n);

  cout << res << endl;


  return 0;
}

double norma(const double a[], int &n){
  double res;
  res = sqrt(prodScalare(a, a, n));
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
