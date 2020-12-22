#include <stdlib.h>
#include <stdio.h>

double** leggiMatrice(FILE* in, int righe, int colonne);

int main(int argc, char const *argv[]) {
  FILE* myin, myout;
  int nRighe, nColonne;
  double** matrice;
  int i, j;

  if(argc != 2){
    printf("Hai inserito argomenti sbagliati, forma: ./a.out <fileinput>\n");
    exit(0);
  }

  myin = fopen(argv[1], "r");

  if(myin == NULL){
    printf("Il file non esiste.\n");
    exit(0);
  }

  fscanf(myin, "%d", &nRighe);
  fscanf(myin, "%d", &nColonne);

  matrice = leggiMatrice(myin, nRighe, nColonne);

  fclose(myin);

  //stampa matrice
  for(i=0; i<nRighe; i++){
    for(j=0; j<nColonne; j++){
      printf("%lf\t", matrice[i][j]);
    }
    printf("\n");
  }
  //deallocazione matriceDouble
  for(i=0; i<nRighe; i++){
    free(matrice[i]);
  }
  free(matrice);
  //fine deallocazione
  return 0;
}

double** leggiMatrice(FILE* in, int righe, int colonne){
  double** matrice = malloc(sizeof(double*)*righe);
  int i, j;
  for( i=0; i<righe; i++){
    matrice[i] = malloc(sizeof(double)*colonne);
  }

  for( i=0; i<righe; i++){
    for( j=0; j<colonne; j++){
      fscanf(in, "%lf", &matrice[i][j]);
    }
  }
  return matrice;
}
