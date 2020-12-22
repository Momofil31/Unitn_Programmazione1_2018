//generatore casuale di lettere minuscole
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void inizializza();

int main() {
  char lettera;
  for (int i = 0; i < 100; i++) {
    lettera = (rand()%('z'-'a')) + 'a';

    cout << lettera << " ";
  }

  return 0;
}

void inizializza(){
  unsigned int seed = time(NULL);
  srand(seed);
}
