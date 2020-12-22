#include <iostream>
#include "persona.h"
#include "tree.h"

using namespace std;

void cercatutti(const tree &t, char cognome[]);

int main () {
  persona * p;
  tree agenda;
  char cognome[MAX_DIM];
  char indirizzo[MAX_DIM];
  char res;
  tree tmp;
  init(agenda);
  do {
    cout << "\nOperazioni possibili:\n"
         << "Inserimento (i)\n"
         << "Ricerca tutti per cognome (r)\n"
         << "Stampa ordinata (s)\n"
         << "Fine (f)\n";
    cin >> res;
    switch (res) {
      case 'i':
        p = leggi_persona();
        inserisci(agenda,p);
        break;
        case 'r':
          cout << "Cognome? : ";
          cin >> cognome;
          cout << endl;
          cercatutti(agenda,cognome);
        break;
        case 's':
          cout << "Stampa ordinata:\n";
          stampa_ordinata(agenda);
        break;
        case 'f':
        break;
        default:
        cout << "Optione errata\n";
      }
  } while (res != 'f');
}


void cercatutti(const tree &t, char cognome[]) {
  tree res;
  if (t == NULL) {
  }
  else if (strcmp(cognome, t->p->cognome) == 0) {
    cercatutti(t->left, cognome);
    stampa_persona(t->p);
  }
  else if (strcmp(cognome, t->p->cognome) < 0) {
    cercatutti(t->left, cognome);
  }
  else {
    cercatutti(t->right, cognome);
  }
}
