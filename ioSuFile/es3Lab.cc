#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int LUNGHEZZA_PAROLA = 4;
const int LUNGHEZZA_RIGA = 4;
const char DELIMITATORI[] = ", . ;:-";

void parserRighe(char riga[], int dim);

int main (int argc, char * argv[])
{
  fstream myin,myout;
  char riga[LUNGHEZZA_RIGA];

  if (argc<3) {
    cout << "Usage: ./a.out <sourcefile> <targetfile>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);
  if (myin.fail()) {
     cerr << "Il file " << argv[1] << " non esiste\n";
     exit(0);
  }
  do {
    myin.getline(riga, LUNGHEZZA_RIGA);
    if (riga[0]!='\0'){
      // cout << "\t[" << riga << "]\n";
      parserRighe(riga, LUNGHEZZA_RIGA);
    }
  } while (riga[0]!='\0');


  return 0;
}

void parserRighe(char riga[], int dim){
  int parolaCounter = 0;
  for (int i=0; riga[i] != '-' && parolaCounter <4 && i < dim; i++){
    cout << riga[i];
    parolaCounter++;
    if(parolaCounter == 4){
      cout << ".";
      parolaCounter = 0;
    }
  }
}
