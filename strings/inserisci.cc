#include <iostream>

using namespace std;

const int SIZE = 1000;

bool inserisci(char array[], int& dim, int elemento);
void stampaArray(char array[], int& dim);

int main(int argc, char const *argv[]) {
  char array[SIZE];
  int dim = 0;
  char comando;
  do {
    stampaArray(array, dim);
    cout << "Introdurre comando: ";
    cin >> comando;
    if(comando == 'i'){
      char elemento;
      cout << "Inserisci elemento: ";
      cin >> elemento;
      if(!inserisci(array, dim, elemento)){}
        cout << "Errore, non c'è più spazio" << endl;
    }
  } while (!(comando = 'e'));

  return 0;
}

void stampaArray(char array[], int& dim){
  for (size_t i = 0; i < dim; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

bool inserisci(char array[], int& dim, int elemento){
  bool res = false;
  if(dim < SIZE){
    int i;
    for(i=0; i<dim && array[i] < elemento; i++);

    dim++;
    for(int j=dim; j>i; j--){
      array[j]=array[j-1];
    }
    array[i] = elemento;
    res = true;
  }
  return res;
}
