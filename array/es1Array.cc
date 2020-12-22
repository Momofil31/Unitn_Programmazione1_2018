#include <iostream>
using namespace std;

double prodScalare(const double a[], const double b[]);
const int dim = 3;

int main(int argc, char const *argv[]) {
  double a[dim] = {1, 2, 3};
  double b[dim] = {1, 2, 3};
  double res;
  res = prodScalare(a, b);

  cout << res << endl;


  return 0;
}

double prodScalare(const double a[], const double b[]){
  double res = 0;
  for(int i=0; i<dim; i++){
    res += a[i]*b[i];
  }
  return res;
}
