#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int DIM = 256;

int main(int argc, char const *argv[]) {
  fstream myin_a, myin_b, myout;
  int nRighe_a, nRighe_b;
  char parola_a[DIM], parola_b[DIM];

  if (argc != 4) {
    cerr << "Formato argomenti errato! Es: ./a.out <input1> <input2> <output>" << endl;
    exit(0);
  }

  //tentativo di apertura dei due stream e gestione eventuale fallimento
  myin_a.open(argv[1], ios::in);
  myin_b.open(argv[2], ios::in);

  if (myin_a.fail() || myin_b.fail()) {
    cerr << "Errore nella lettura dei file di input." << endl;
    exit(0);
  }

  //leggo numero di parole di ciascun file (prima riga)
  myin_a >> nRighe_a;
  myin_b >> nRighe_b;

  //apro file output (dò per scontato che non fallisca mai)
  myout.open(argv[3], ios::out);

  //leggo e stampo le parole
  myin_a >> parola_a;
  myin_b >> parola_b;
  for (int a=0, b=0; a<=nRighe_a && b<=nRighe_b;) {
    cout << parola_a << " " << parola_b << endl;
    if (strcmp(parola_a, parola_b) == 0){
      myout << parola_a << endl;
      myin_a >> parola_a;
      a++;
      myin_b >> parola_b;
      b++;
    } else {
      if (strcmp(parola_a, parola_b) < 0) {
        a++;
        myin_a >> parola_a;
      }
      if (strcmp(parola_a, parola_b) > 0) {
        b++;
        myin_b >> parola_b;
      }
    }
  }
  myin_a.close();
  myin_b.close();
  myout.close();

  return 0;
}
