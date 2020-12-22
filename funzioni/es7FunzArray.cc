//stampare i primi n elementi della serie di fibonacci, dove n è un intero acquisito da tastiera
//con una funzione ricorsiva;

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

void inizializza();
int lanciaDado();
void scambia(int&, int&);
void ordina(int[], int);
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

void ordina(int vettore[], int dim){
  for (int i=0; i<dim; i++){
    if (vettore[i] > vettore[dim-1])
      scambia(vettore[i], vettore[dim-1]);
  }
}

bool attacco(){
  int dim = 3;
  int attacco[dim];
  int difesa[dim];
  int scoreAttacco = 0;
  int scoreDifesa = 0;

  cout << "Lancio i dadi Attacco." << endl;
  for (int i = 0; i < dim; i++) {
    attacco[i] = lanciaDado();
    cout << attacco[i] << " ";
  }
  cout << endl;

  cout << "Lancio i dadi Difesa." << endl;
  for (int i = 0; i < dim; i++) {
    difesa[i] = lanciaDado();
    cout << difesa[i] << " ";
  }
  cout << endl;

  ordina(attacco, dim);
  ordina(difesa, dim);

  for (int i = 0; i < dim; i++) {
    if(difesa[i] >= attacco[i]){
      scoreDifesa++;
    }
    else {
      scoreAttacco++;
    }
  }

  cout << "punteggio Attacco: " << scoreAttacco << endl;
  cout << "punteggio Difesa: " << scoreDifesa << endl;

  if (scoreAttacco > scoreDifesa)
    return true;
  else
    return false;
}
