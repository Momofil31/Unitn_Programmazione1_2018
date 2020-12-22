#include <iostream>

#include "albero.h"

using namespace std;

int main() {
  char res;
  Albero albero;
  int val;
  init(albero);
  do {
    cout << "\nOperazioni possibili:\n"
         << " Inserimento (i)\n"
         << " Ricerca (r)\n"
         << " Stampa ordinata (s)\n"
         << " Altezza (a)\n"
         << " Fine (f)\n";
    cout << "Operazione selezionata: ";
    cin >> res;
    switch (res) {
      case 'i':
        cout << "Valore : ";
        cin >> val;
        if (inserisci(albero, val) == false) {
          cout << "Valore gia` presente!" << endl;
        }
        break;
      case 'r':
        cout << "Valore: ";
        cin >> val;
        if (cerca(albero, val)) {
          cout << "Valore presente: " << val << endl;
        } else {
          cout << "Valore non presente" << endl;
        }
        break;
      case 's':
        if (isEmpty(albero)) {
          cout << "Albero vuoto!" << endl;
        } else {
          stampa(albero);
        }
        break;
      case 'a':
        cout << height(albero) << endl;
      case 'f':
        break;
      default:
        cout << "Opzione errata\n";
    }
  } while (res != 'f');

  return 0;
}
