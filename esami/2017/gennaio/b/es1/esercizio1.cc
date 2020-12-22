#include <iostream>
#include <fstream>

using namespace std;

const int MAX_DIM = 256;

int main(int argc, char const *argv[]) {
  fstream myin_a, myin_b, myout;
  char riga_a[MAX_DIM], riga_b[MAX_DIM];

  // controllo se gli argomenti vanno bene
  if (argc != 4) {
    cerr << "Formato argomenti errato! Es: ./a.out <file_input_a> <file_output> <file_input_b>" << endl;
    exit(0);
  }

  //tentativo di apertura file input
  myin_a.open(argv[1], ios::in);
  myin_b.open(argv[2], ios::in);
  //controllo se l'apertura è andata a buon fine
  if (myin_a.fail() || myin_b.fail()) {
    cerr << "Errore nell'apertura dei file di input." << endl;
    exit(0);
  }
  //chido file b per utilizzp futuro
  myin_b.close();

  //apro file file output
  myout.open(argv[3], ios::out);
  //inizio procedura lettura file a
  myin_a.getline(riga_a, MAX_DIM);
  while (!myin_a.eof()) {
    //stampo riga_a;
    myout << riga_a << endl;
    //se riga_a è uguale a "COPIARE" stampo il file b
    if (strcmp(riga_a, "COPIARE") == 0) {
      myin_b.open(argv[2], ios::in);
      myin_b.getline(riga_b, MAX_DIM);
      while (!myin_b.eof()) {
        myout << riga_b << endl;
        myin_b.getline(riga_b, MAX_DIM);
      }
      myin_b.close();
    }
    myin_a.getline(riga_a, MAX_DIM);
  }
  myin_a.close();
  myout.close();
  return 0;
}
