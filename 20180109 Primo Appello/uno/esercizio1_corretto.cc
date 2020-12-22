#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//uno in più per gestire il carattere terminatore '\0'
const int DIM = 31;

void toMaiusc(char &ch);

int main(int argc, char const *argv[]) {
  fstream myin, myout;
  char parola[DIM];
  int len;
  //controllo correttezza argomenti
  if (argc != 3) {
    cerr << "Errore nel formato degli argomenti" << endl;
    return 1;
  }

  //tentativo di apertura stream input e gestione eventuale Errore
  myin.open(argv[1], ios::in);

  if (myin.fail()) {
    cerr << "Errore nell'apertura dello stream input." << endl;
    return 1;
  }

  //apertura stream output (do per scontato che non fallisca mai)
  myout.open(argv[2], ios::out);

  //leggo la prima parola. se primo carattere e' minuscolo, trasformo
  myin >> parola;
  toMaiusc(parola[0]);

  //leggo il resto del testo e trasformo quando necessario
  while (!myin.eof()) {
    myout << parola << " ";
    len = strlen(parola);
    if (parola[len-1] == ',' || parola[len-1] == ';' || parola[len-1] == ':') {
      myin >> parola;
      toMaiusc(parola[0]);
    } else {
      myin >> parola;
    }
  }

  //chiusura stream input
  myin.close();
  myout.close();

  return 0;
}

void toMaiusc(char &ch) {
  if (ch >= 'a' && ch <= 'z') {
    ch += 'A' - 'a';
  }
}
