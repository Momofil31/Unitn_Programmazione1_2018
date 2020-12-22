#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "giardino_mod.h"

using namespace std;

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
        cout << "*" << '\t';
      } else {
        cout << nomiSpecie[giardino[i][j] -> nome_specie] << '\t';
      }
    }
    cout << endl;
  }
}

void eliminaGiardino(puntAlbero** giardino, int dimX, int dimY){
  for (int i = 0; i < dimX; i++)
      delete [] giardino[i];

  delete [] giardino;
}
