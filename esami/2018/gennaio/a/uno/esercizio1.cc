#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int DIM = 256;

int main(int argc, char const *argv[]) {
  fstream myin, myout;
  int numRighe;
  int righeEffettive;
  int righeDaAllocare;
  char riga[DIM];
  int lun;

  if (argc =! 4) {
    cerr << "Formato argomenti errao! Es: ./a.out <input> <numRighe> <output>" << endl;
    exit(0);
  }

  numRighe = atoi(argv[2]);

  myin.open(argv[1], ios::in);
  if (myin.fail()) {
    cerr << "Errore nell'apertura del file di input." << endl;
    exit(0);
  }

  //faccio una prima lettura per contare quante righe ci sono
  righeEffettive = 0;
  myin.getline(riga, DIM);
  while (!myin.eof()) {
    righeEffettive++;
    myin.getline(riga, DIM);
  }
  myin.close();

  //se il file e' formato da meno righe di quante sono state richieste
  //allora alloco quelle effettive altrimenti quelle richieste come argomento
  (righeEffettive < numRighe) ? righeDaAllocare = righeEffettive : righeDaAllocare = numRighe;

  //creo array di righe (allocato dinamicamente)
  char ** righe = new char * [righeDaAllocare];

  //apro di nuovo il file input in lettura
  myin.open(argv[1], ios::in);

  //lettura e inserimento nell'array;
  myin.getline(riga, DIM);
  for (int i=0; i<righeDaAllocare && !myin.eof(); i++) {
    lun = strlen(riga);
    righe[i] = new char[lun+1];
    for (int j=0; j<lun; j++) {
      if (riga[j] != ' ' && riga[j] != '\t') {
        //Trasforno il carattere come da consegna
        righe[i][j] = (j%2 == 0 ? '*' : '+');
      } else {
        //aggiungo il separatore
        righe[i][j] = riga[j];
      }
    }
    //aggiungo il terminatore di riga
    righe[i][lun] = '\0';
    myin.getline(riga, DIM);
  }
  myin.close();

  myout.open(argv[3], ios::out);
  //stampo in ordine inverso con cambio caratteri
  for (int i=righeDaAllocare-1; i>=0; i--) {
    myout << righe[i] << endl;
  }
  myout.close();

  //dealloco l'array dinamico
  for (int i=0; i<righeDaAllocare; i++) {
    delete [] righe[i];
  }

  return 0;
}
