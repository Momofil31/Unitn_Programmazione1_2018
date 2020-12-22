#include <iostream>
#include <fstream>

using namespace std;
const int MAX_LEN = 80;

int main(int argc, char const *argv[]) {
  fstream myin, myout;
  int numeroRighe;
  char riga[MAX_LEN];

  if (argc != 4) {
    cerr << "Formato argomenti errato! Es: ./a.out <input> <numeroRighe> <output>" << endl;
    exit(0);
  }

  numeroRighe = atoi(argv[2]);
  char** righe = new char* [numeroRighe];

  myin.open(argv[1], ios::in);
  if (myin.fail()) {
    cerr << "Errore nell'apertura del file" << endl;
    exit(0);
  }

  myin.getline(riga, MAX_LEN);
  for (int i=0; i<numeroRighe && !myin.eof(); i++) {
    righe[i] = new char [strlen(riga)+1];
    strcpy(righe[i], riga);
    myin.getline(riga, MAX_LEN);
  }
  myin.close();

  myout.open(argv[3], ios::out);
  //stampo
  for (int i=numeroRighe; i>=0; i--) {
    if (i%2 == 0) {
      myout << righe[i] << endl;
    }
  }
  myout.close();
  return 0;
}
