#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int NUMERO_SPECIE = 5;

enum Specie {PINO, ROVERE, FAGGIO, ABETE, NOCE};
const char nomiSpecie[NUMERO_SPECIE] = {'P', 'R', 'F', 'A', 'N'};

struct Albero {
  Specie nome_specie;
  int numero_id;
};

typedef Albero* puntAlbero;

puntAlbero** preparaGiardino(int dimX, int dimY);
void riempiGiardino(puntAlbero** giardino, int dimX, int dimY, int quanti[]);
void stampaGiardino(puntAlbero** giardino, int dimX, int dimY);

int main(int argc, char const *argv[]) {
  int dimX, dimY;
  puntAlbero** giardino;

  int quanti[NUMERO_SPECIE] = {3, 1, 2, 1, 3};

  if (argc != 3){
    cerr << "servono 2 argomenti <dimX> <dimY>" << endl;
    exit(0);
  }

  dimX = atoi(argv[1]);
  dimY = atoi(argv[2]);

  if (dimX < 9 || dimY < 9){
    cerr << "ERRORE: inserire dimensioni >= 9" << endl;
    exit(0);
  }

  giardino = preparaGiardino(dimX, dimY);
  riempiGiardino(giardino, dimX, dimY, quanti);
  stampaGiardino(giardino, dimX, dimY);
  return 0;
}

puntAlbero ** preparaGiardino(int dimX, int dimY){
  //Alloca un array di array (matrice dinamica) di tipo "puntatore ad Albero"
  puntAlbero ** matrice = new Albero* *[dimX];
  for (int i = 0; i < dimX; i++) {
    //Alloca la riga di matrice
    matrice[i] = new Albero*[dimY];
    for (int j=0; j<dimY; j++)
      //inizializza a NULL ogni elemento della matrice
      matrice[i][j] = NULL;
  }
  return matrice;
}

void riempiGiardino(puntAlbero** giardino, int dimX, int dimY, int quanti[]){
  int posX, posY;
  srand (time(NULL));
  for (int i = 0; i < NUMERO_SPECIE; i++) {
    for (int j = 0; j < quanti[i]; j++) {
      do {
        posX = rand()%dimX;
        posY = rand()%dimY;
      } while(giardino[posX][posY] != NULL);

      puntAlbero nuovoAlbero = new Albero;
      nuovoAlbero -> nome_specie = (Specie)i; //cast a tipo enum (come fare uno switch
      nuovoAlbero -> numero_id = j+1;
      giardino[posX][posY] = nuovoAlbero;
    }
  }
}

void stampaGiardino(puntAlbero** giardino, int dimX, int dimY){
  for (int i = 0; i < dimX; i++) {
    for (int j = 0; j < dimY; j++) {
      if(giardino[i][j] == NULL){
        cout << "VUOTO" << '\t';
      } else {
        cout << nomiSpecie[giardino[i][j] -> nome_specie] << '\t';
      }
    }
    cout << endl;
  }
}
