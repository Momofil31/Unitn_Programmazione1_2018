#include <iostream>

using namespace std;

const int SIZE = 1000;

void stampaVettore(int array[], int& dim);
void stampaMatrice(int matrix[][SIZE], int& dimR, int& dimC);
void diagonalePrincipale(int matrix[][SIZE], int array[], int& dim);

int main(int argc, char const *argv[]) {
  int matrice[SIZE][SIZE] = {{0,1,3}, {4, 5, 6}, {8, 10, 12}};
  int vettore[SIZE] = {};
  int dim = 3;
  int dimR = 3;
  int dimC = 3;

  stampaMatrice(matrice, dimR, dimC);
  diagonalePrincipale(matrice, vettore, dim);
  cout << "-----------------------------" << endl;
  stampaVettore(vettore, dim);

  return 0;
}

void diagonalePrincipale(int matrix[][SIZE], int array[], int& dim){
  for (int i = 0; i < dim; i++)
    array[i] = matrix[i][i];
}

void stampaVettore(int array[], int& dim){
  for (int i = 0; i < dim; i++)
    cout << array[i] << '\t';

  cout << endl;
}

void stampaMatrice(int matrix[][SIZE], int& dimR, int& dimC){
  for (int i = 0; i < dimR; i++) {
    for(int j=0; j<dimC; j++)
      cout << matrix[i][j] << '\t';
    cout << endl;
  }
}
