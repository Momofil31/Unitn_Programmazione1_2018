#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "giardino_mod.h"

using namespace std;

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
  eliminaGiardino(giardino, dimX, dimY);
  
  return 0;
}
