#include <iostream>
#include <cmath>

using namespace std;

int potenza(int n, int esp);

int main () {
  int numero, esponente;
  cout << "Inserisci un numero intero e l'esponente: ";
  cin >> numero >> esponente;
  cout << "La potenza e': " << potenza(numero, esponente) << endl;
	return 0;
}

int potenza(int n, int esp){
  int res = 0;
  if (esp == 0)
    res = 1;
  else
    res = n * potenza(n, esp-1);
  return res;
}
