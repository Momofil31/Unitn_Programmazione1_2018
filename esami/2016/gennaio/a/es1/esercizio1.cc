#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int DIM_RIGA = 80;

int main(int argc, char const *argv[]) {
  fstream myin, myout;
  char riga[DIM_RIGA];

  if(argc != 4){
    cerr << "Formato argomenti errato: ./a.out <input> <numero_righe> <output>" << endl;
    exit(0);
  }

  myin.open(argv[1], ios::in);

  if(myin.fail()){
    cerr << "Errore nell'apertura del file di input." << endl;
    exit(0);
  }

  int numeroRighe = atoi(argv[2]);

  char** arrayRighe = new char * [numeroRighe];

  myin.getline(riga, DIM_RIGA);

  for (int i=0; i<numeroRighe && !myin.eof(); i++){
    arrayRighe[i] = new char [strlen(riga)+1];
    strcpy(arrayRighe[i], riga);
    myin.getline(riga, DIM_RIGA);
  }
  myin.close();

  myout.open(argv[3], ios::out);

  for (int i=numeroRighe-1; i>0; i--){
    if (i%2 != 0) {
      myout << arrayRighe[i] << endl;
    }
    delete [] arrayRighe[i];
  }
  myout.close();
  return 0;
}
