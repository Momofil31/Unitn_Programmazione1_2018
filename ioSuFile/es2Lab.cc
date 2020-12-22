
// Numeri in ingresso interi
// Regola:
// n<50 => moltiplica per 1.08
// 50 <= n <= 100 moltiplica per 1.05
// n > 100 moltiplica per 1.02

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

double sconta(int prezzo);

int main (int argc, char * argv[])
{
  fstream myin,myout;
  int prezzo;

  if (argc!=3) {
    cout << "Usage: ./a.out <sourcefile> <targetfile>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);
  if (myin.fail()) {
     cerr << "Il file " << argv[1] << " non esiste\n";
     exit(0);
  }

  myout.open(argv[2],ios::out);
  while (myin >> prezzo) {
    myout << sconta(prezzo) << endl;
  }
  myin.close();
  myout.close();
  return 0;
}
double sconta(int prezzo){
  double res = 0.0;
  if (prezzo <= 50)
    res = prezzo * 1.08;
  else if (prezzo <=100)
    res = prezzo * 1.05;
      else if (prezzo > 100)
        res = prezzo * 1.02;
  return res;
}
