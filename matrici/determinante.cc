#include <iostream>

using namespace std;

const int DIM = 100;

double determinante(const double a[][DIM], int d1, int d2, int eliminaRiga, int eliminaColonna);

int main(int argc, char const *argv[]) {

  double a[DIM][DIM] = {{1, 2, 3}, {4, 5, 6},  {7, 8, 9}};

  double res = determinante(a, 3, 3, -1, -1);
  /* code */
  return 0;
}

double determinante(const double a[][DIM], int d1, int d2, int eliminaRiga, int eliminaColonna){
  double res = 0.0;
  if(d1 == 2 && d2 == d1){
    res = a[0][0]*a[1][1] - a[1][0]*a[0][1];
  } else {


  }
  return 0.0;
}
