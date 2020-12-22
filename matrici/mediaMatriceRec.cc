#include <iostream>

using namespace std;

const int SIZE = 3;

double media(int matrix[][SIZE], int& dimR, int& dimC);
void stampaMatrice(int matrix[][SIZE], int& dimR, int& dimC);
double somma(int matrice[][SIZE], int pivotR, int pivotC);

int main(int argc, char const *argv[]) {
  int matrice[SIZE][SIZE] = {{0, 2, 3}, {4, 5, 6}, {8, 10, 12}};

  int dimR = 3;
  int dimC = 3;

  stampaMatrice(matrice, dimR, dimC);

  cout << "la media e': " << media(matrice, dimR, dimC) << endl;

  return 0;
}

double media(int matrix[][SIZE], int& dimR, int& dimC){
   double media = 0.0;
   double res = 0;
   res = somma(matrix, 0, 0);
   cout << "la somma e': " << res;
   media = res / (dimR*dimC);
   return media;
}

double somma(int matrice[][SIZE], int pivotR, int pivotC){
  double res;
  if(pivotR == SIZE-1 && pivotC == SIZE-1)
    res = matrice[pivotR][pivotC];
  else {
    if(pivotC == SIZE-1)
      res = matrice[pivotR][pivotC] + somma(matrice, pivotR+1, pivotC-SIZE+1);
    else
      res = matrice[pivotR][pivotC] + somma(matrice, pivotR+1, pivotC+1);
  }
  return res;
}

void stampaMatrice(int matrix[][SIZE], int& dimR, int& dimC){
  for (int i = 0; i < dimR; i++) {
    for(int j=0; j<dimC; j++)
      cout << matrix[i][j] << '\t';
    cout << endl;
  }
}
