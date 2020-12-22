//stampare i primi n elementi della serie di fibonacci, dove n è un intero acquisito da tastiera
//con una funzione ricorsiva;

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

void inizializza();
int lanciaDado();
void scambia(int&, int&);
void ordina(int&, int&, int&);
bool confronta(int, int);
bool attacco();


int main(){
  inizializza();
  if (attacco())
    cout << "Ha vinto l'attaccante." << endl;
  else
    cout << "Ha vinto il difensore." << endl;
  return 0;
}

void inizializza(){
  unsigned int seed = time(NULL);
  srand(seed);
}

int lanciaDado(){
  int numero;
  numero = rand() % 6 + 1;
  return numero;
}

void scambia(int& a, int& b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void ordina(int& a, int& b, int& c){
  if (a<b) scambia(a, b);
  if (a<c) scambia(a, c);
  if (b<c) scambia(b, c);
}

bool confronta(int a, int b){
  bool isAMajB = false;
  if (a > b) isAMajB = true;

  return isAMajB;
}

bool attacco(){
  bool haVinto = false;
  int a1, a2, a3;
  int d1, d2, d3;
  int scoreAttacco = 0;
  int scoreDifesa = 0;

  cout << "Lancio i dadi Attacco." << endl;

  a1 = lanciaDado();
  a2 = lanciaDado();
  a3 = lanciaDado();

  cout << "Lancio i dadi Difesa." << endl;

  d1 = lanciaDado();
  d2 = lanciaDado();
  d3 = lanciaDado();

  cout << " " << a1 << " " << a2 << " " << a3 << endl;
  cout << " " << d1 << " " << d2 << " " << d3 << endl;

  ordina(a1, a2, a3);
  ordina(d1, d2, d3);

  cout << "Dopo ordinamento:" << endl;
  cout << "Attacco: " << a1 << " " << a2 << " " << a3 << endl;
  cout << "Difesa: " << d1 << " " << d2 << " " << d3 << endl;

  if (confronta(a1, d1))
    scoreAttacco++;
  else
    scoreDifesa++;

  if (confronta(a2, d2))
    scoreAttacco++;
  else
    scoreDifesa++;

  if (confronta(a3, d3))
    scoreAttacco++;
  else
    scoreDifesa++;

  cout << "Punteggio Attacco: " << scoreAttacco << endl;
  cout << "Punteggio Difesa: " << scoreDifesa << endl;

  if (scoreAttacco > scoreDifesa)
    haVinto = true;

  return haVinto;
}
