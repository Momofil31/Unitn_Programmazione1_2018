#include <iostream>
#include <fstream>

using namespace std;

const int DIM = 81;

bool isEmail(char parola[]);
bool containsRightCh(char parola[], int dim);
int len(char parola[]);
bool isAllowed(char ch);


int main(int argc, char const *argv[]) {
  fstream myin;
  char parola[DIM];

  if (argc != 2) {
    cerr << "Formato argomenti errato! Es: ./a.out <input>" << endl;
    exit(0);
  }

  myin.open(argv[1], ios::in);

  if (myin.fail()) {
    cerr << "Errore nell'apertura del file." << endl;
    exit(0);
  }

  myin >> parola;
  while (!myin.eof()) {
    if (isEmail(parola)) {
      cout << parola << endl;
    }
    myin >> parola;
  }
  myin.close();
  return 0;
}

bool isEmail(char parola[]) {
  int lunghezza = len(parola);
  bool res = true;
  if (lunghezza < 2)
    res = false;
  if (!containsRightCh(parola, lunghezza))
    res = false;
  if (parola[0] == '.' || parola[lunghezza-1] == '.')
    res = false;
  return res;
}

bool containsRightCh(char parola[], int dim) {
  bool res = true;
  int countAt = 0;
  char ch;
  for (int i=0; res == true && i<dim; i++) {
    ch = parola[i];
    if (!isAllowed(ch))
      res = false;
    if (ch == '@')
      countAt++;
  }
  if (countAt != 1)
    res = false;
  return res;
}

int len(char parola[]) {
  int i = 0;
  while (parola[i] != '\0' && i < DIM) {
    i++;
  }
  return i;
}

bool isAllowed(char ch) {
  if ((ch >= 'a' && ch <= 'z')
      || (ch >= 'A' && ch <= 'Z')
      || (ch >= '0' && ch <= '9')
      || ch == '_'
      || ch == '@'
      || ch == '.')
      return true;
    else
      return false;
}
