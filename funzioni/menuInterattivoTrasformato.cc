/*
  Implementare la funzione media, che calcola la media in maniera ricorsiva,
  ma in modo interattivo; alla fine di ogni esecuzione, all'utente viene
  richiesto se inserire un nuovo numero per aggiornare la media.
  In questo caso, la funzione invoca nuovamente se' stessa; altrimenti, termina.

  NB: ci sono due parametri, la somma dei numeri introdotti fino a quel momento,
  e un contatore che conta il numero di invocazioni (cossisponde al numero
  di valori introdotti, e serve per calcolare la media ad ogni passaggio).
*/


#include <iostream>

using namespace std;

void media(long s, int ctr);

int conta_cifre(long x);

int main () {
  media(0l, 0);
	return 0;
}

void media(long s, int ctr){
  int n;
  double res;
  char continua;

  cout << "Inserisci un numero: ";
  cin >> n;
  s += n;
  ctr++;
  res = double(s)/ctr;
  cout << "La media parziale e': " << res << endl;
  cout << "Continuare? [s/n] ";
  cin >> continua;
  if (continua == 's')
    media(s, ctr);
  else
    cout << "La media finale e': " << res << endl;
}
