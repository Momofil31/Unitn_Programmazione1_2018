#include <iostream>
#include <fstream>

using namespace std;

char** leggiMatrice(fstream &, int , int);
int main(int argc, char const *argv[]) {
  //dichiaro variabili
  fstream myin;
  int righe, colonne;
  char** matrice;

  //controllo se formato argomenti e' corretto
  if (argc != 2){
    cerr << "Formato argomenti sbagliato: ./a.out <inputFile>" << endl;
    exit(0);
  }

  //apro file input
  myin.open(argv[1], ios::in);

  //controllo se e' stato aperto e gestisco eventuale errore
  if (myin.fail()){
    cerr << "Errore nell'apertura del file" << endl;
    exit(0);
  }
  //leggo numero righe e numero colonne

  myin >> righe >> colonne;

  matrice = leggiMatrice(myin, righe, colonne);

  // //stampo matrice per controllare di aver fatto giusto
  // for (int i = 0; i < righe; i++) {
  //   for (int j = 0; j < colonne; j++) {
  //     cout << matrice[i][j] << '\t';
  //   }
  //   cout << endl;
  // }
  // //dealloco matrice
  // for (int i = 0; i < righe; i++) {
  //   delete [] matrice[i];
  // }
  // delete [] matrice;

  return 0;
}

char** leggiMatrice(fstream &in, int r, int c){
  char** matrice = new char*[r];
  for (int i = 0; i < r; i++) {
    matrice[i] = new char[c];
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      in >> matrice[i][j];
    }
  }
  return matrice;
}
