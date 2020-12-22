/*
3) scrivere un programma che prenda due file
- uno di testo
- l'altro con una mappa iniettiva tra caratteri
  e riscriva su un nuovo file il testo criptato secondo la mappa di caratteri.
*/

#include <iostream>
#include <fstream>

using namespace std;

const int DIM = 21;

char ricerca(char elemento, char mappaA[], char mappaB[]);

int main(int argc, char const *argv[]) {
  char a[DIM], b[DIM];
  char testo[100];
  char testo2[100];

  fstream myin, myout, myapp;

  if (argc!=4) {
  cerr << "Usage: ./a.out <map> <sourcefile> <targetfile>\n";
  exit(0);
  }

  myin.open(argv[1], ios::in);
  if (myin.fail()) {
   cerr << "Il file " << argv[1] << " non esiste\n";
   exit(0);
  }

  //inserisco la mappa da file in un vettore a per i caratteri in chiaro e un vettore b per quelli criptati
  int c = 0;
  int cA=0, cB=0;

  while(!myin.fail()){
    if(c%2 == 0){
      myin >> a[cA];
      cA++;
      c++;
    } else {
      myin >> b[cB];
      cB++;
      c++;
    }
  }
  myin.close();

  // leggo da file il testo da criptare
  myin.open(argv[2],ios::in);
  if (myin.fail()) {
   cerr << "Il file " << argv[1] << " non esiste\n";
   exit(0);
  }

  char ch;
  int count = 0;
  while(myin.get(ch)){
    testo[count] = ch;
    count++;
  }
  myin.close();

  // stampo a video il testo in chiaro (per debug)
  for(int i=0; i<count; i++){
    cout << testo[i];
  }

  // scrivo su file il "testo criptato"
  myout.open(argv[3], std::fstream::out);
  for(int i=0; i<count; i++){
    cout << testo2[i]; //stampa a video per debug
    myout << ricerca(testo[i], a, b);;
  }
  myout.close();

  return 0;
}

char ricerca(char elemento, char mappaA[], char mappaB[]){
  bool trovato = false;
  char res = elemento;
  int i;
  for(i=0; i<DIM && trovato == false; i++){
    if(elemento == mappaA[i])
      trovato = true;
  }

  if(trovato == true){
    res = mappaB[i-1];
  }
  return res;
}
