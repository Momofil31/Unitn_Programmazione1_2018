#include <iostream>
#include <fstream>

using namespace std;

double** leggiMatrice(fstream &in, int righe, int colonne);

int main(int argc, char const *argv[]) {
  fstream myin, myout;
  int nRighe, nColonne;
  double** matrice;

  if(argc != 2){
    cout << "Hai inserito argomenti sbagliati, forma: ./a.out <fileinput>" << endl;
    exit(0);
  }

  myin.open(argv[1], ios::in);

  if(myin.fail()){
    cout << "Il file non esiste." << endl;
    exit(0);
  }

  myin >> nRighe;
  myin >> nColonne;

  matrice = leggiMatrice(myin, nRighe, nColonne);

  myin.close();
  //stampa matrice
  for(int i=0; i<nRighe; i++){
    for(int j=0; j<nColonne; j++){
      cout << matrice[i][j] << '\t';
    }
    cout << endl;
  }
  //deallocazione matriceDouble
  for(int i=0; i<nRighe; i++){
    delete [] matrice[i];
  }
  delete [] matrice;
  //fine deallocazione
  return 0;
}

double** leggiMatrice(fstream &in, int righe, int colonne){
  double** matrice = new double*[righe];
  for(int i=0; i<righe; i++){
    matrice[i] = new double[colonne];
  }

  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      in >> matrice[i][j];
    }
  }
  return matrice;
}
