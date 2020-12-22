#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_DIM = 256;
const char PAROLA_CHIAVE[] = "INCLUDI";
int main(int argc, char const *argv[]) {
  fstream myin_a, myin_b, myout;

  char riga_a[MAX_DIM];
  char riga_b[MAX_DIM];

  if (argc != 4) {
    cerr << "Formato argomenti errato! Es: ./a.out <file_input_a> <file_input_b> <file_output>" << endl;
    exit(0);
  }

  myin_a.open(argv[1], ios::in);
  myin_b.open(argv[2], ios::in);
  myout.open(argv[3], ios::out);

  if(myin_a.fail()) {
    cerr << "Errore nell lettura del file input A!" << endl;
    exit(0);
  }
  if(myin_b.fail()) {
    cerr << "Errore nell lettura del file input B!" << endl;
    exit(0);
  }
  myin_b.close();

  myin_a.getline(riga_a, MAX_DIM);
  while (!myin_a.eof()) {
    myout << riga_a << endl;
    if (strcmp(PAROLA_CHIAVE, riga_a) == 0) {
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
  myin_b.close();
  myout.close();
  return 0;
}
