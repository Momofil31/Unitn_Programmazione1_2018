#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXLENGHT = 31;

int main(int argc, char const *argv[]) {
  fstream myin, myout;
  char parola[MAXLENGHT];

  if (argc != 3) {
    cerr << "Formato argomenti errato! ./a.out <input> <output>" << endl;
    exit(0);
  }

  myin.open(argv[1], ios::in);
  myout.open(argv[2], ios::out);

  if (myin.fail()) {
    cerr << "Errore nell'apertura del file." << endl;
    exit(0);
  }
  myin >> parola;
  if (parola[0] >= 'a' && parola[0] <= 'z') {
    parola[0] += ('A' - 'a');
  }

  while (!myin.eof()) {
    myout << parola << " ";
    if (parola[strlen(parola)-1] == '.' || parola[strlen(parola)-1] == '?' || parola[strlen(parola)-1] == '!') {
      myin >> parola;
      if (parola[0] >= 'a' && parola[0] <= 'z') {
        parola[0] += ('A' - 'a');
      }
    } else {
      myin >> parola;
    }
  }

  return 0;
}
