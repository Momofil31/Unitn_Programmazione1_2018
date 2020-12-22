// implementare la funzione ricorsiva conta_cifre che conta il numero di cifre
// di un intero long.
// Suggerimento il numero di cifre dipende da quante volte riesco a dividere
// un numero per 10.

#include <iostream>

using namespace std;

int conta_cifre(long x);

int main () {
  long input;
  cout << "Introdurre un numero intero: ";
  cin >> input;
  //cout << input/10;
  cout << "Il numero di cifre: " << conta_cifre(input) << endl;
	return 0;
}

int conta_cifre(long x){
  int res = 0;
  if (x>0){
    res = 1 + conta_cifre(x/10);
  }
  return res;
}
