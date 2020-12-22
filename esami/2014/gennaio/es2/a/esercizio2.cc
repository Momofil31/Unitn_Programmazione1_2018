
#include <iostream> /* cout */
#include <stdlib.h> /* srand , rand */
#include <time.h> /* time */

using namespace std;
//definizione delle funzioni
int tira_dado();
void gioca (int &, int &);

int main() {
  // init random seed
  srand(time(NULL));

  int num_lanci, somma_max;

  gioca(num_lanci, somma_max);
  cout << "Il programma termina al lancio  numero "
  << num_lanci << " con un punteggio massimo di "
  << somma_max << endl;

  return(0);
}

int tira_dado() {
  return 1 + rand() % 6;
}

void gioca(int &nLanci, int &sommaMax) {
  int dado1, dado2, somma;
  sommaMax = 0;
  nLanci = 0;
  while(nLanci < 5 && sommaMax != 12){
    nLanci++;
    dado1 = tira_dado();
    dado2 = tira_dado();
    somma = dado1 + dado2;
    cout << "Lancio " << nLanci
         << ": dado1 = " << dado1
         << ", dado2 = " << dado2
         << ", somma = " << somma
         << endl;
    if (somma > sommaMax) {
      sommaMax = somma;
    }
  }
}
