#include <iostream>
#include <fstream>

using namespace std;

double** leggiMatrice(fstream &in, int r, int c);

int main(int argc, char const *argv[]) {
  //dichiaro variabili
  fstream myin;
  int righe, colonne;
  double** matrice;
  //gestisco caso formato argomenti sbagliati
  if (argc != 2){
    cerr << "Formato sbagliato: ./a.out <inputFile>" << endl;
    exit(0);
  }
  //apro il file
  myin.open(argv[1], ios::in);

  //gestisco errore nell'apertura del file
  if(myin.fail()){
    cerr << "Errore nell'apertura del file." << endl;
    exit(0);
  }
  //leggo dimensioni matrice
  myin >> righe >> colonne;

  matrice = leggiMatrice(myin, righe, colonne);
  myin.close();

  //stampa per controllo
  for (int i = 0; i < righe; i++) {
    for (int j = 0; j < colonne; j++) {
      cout << matrice[i][j] << '\t';
    }
    cout << endl;
  }
  //deallocazione matrice
  for(int i=0; i<righe; i++){
    delete [] matrice[i];
  }
  delete [] matrice;

  return 0;
}

double** leggiMatrice(fstream &in, int r, int c){
  //allocazione matrice
  double** matrix = new double* [r];
  for (int i = 0; i < r; i++) {
    matrix[i] = new double[c];
  }
  //popolamento matrice
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      in >> matrix[i][j];
    }
  }
  return matrix;
}
