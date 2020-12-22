#include <iostream>
#include <fstream>

using namespace std;

int ricorrenze(char []);

int main(int argc, char const *argv[]) {
  fstream myin, myout;

  char parola[256];

  if (argc != 3) {
    cerr << "Formato argomenti sbagliato! Corretto: ./a.out <input> <output>" << endl;
    exit(0);
  }

  myin.open(argv[1], ios::in);
  myout.open(argv[2], ios::out);

  if(myin.fail()){
    cerr << "Errore nell'apertura del file." << endl;
    exit(0);
  }

  myin >> parola;
  while (!myin.eof()) {
    myout << ricorrenze(parola) << " ";
    myin >> parola;
  }

  myin.close();
  myout.close();

  return 0;
}

int ricorrenze(char parola[]){
  int counter = 0;
  for (int i=0; parola[i]!='\0' && i<256; i++) {
    if (parola[i] == 'a') {
      counter++;
    }
  }
  return counter;
}
