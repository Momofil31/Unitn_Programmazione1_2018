#include <iostream>

using namespace std;

const int SIZE = 1000;

double media(int matrix[][SIZE], int& dimR, int& dimC);
void stampaMatrice(int matrix[][SIZE], int& dimR, int& dimC);

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
   int somma = 0;
   for (int i = 0; i < dimR; i++) {
     for(int j=0; j<dimC; j++)
       somma += matrix[i][j];
   }

   media = (double)somma / (dimR*dimC);
   // cout << "Somma: " << somma << endl;
   return media;

}

void stampaMatrice(int matrix[][SIZE], int& dimR, int& dimC){
  for (int i = 0; i < dimR; i++) {
    for(int j=0; j<dimC; j++)
      cout << matrix[i][j] << '\t';
    cout << endl;
  }
}
