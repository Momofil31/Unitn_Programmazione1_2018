#include <iostream>

#include "list.h"

using namespace std;

int main() {
  char res;
  float val;
  list l;
  init(l);
  do {
    cout << "\nOperazioni possibili:\n"
         << " Push front (u)\n"
         << " Pop front (o)\n"
         << " Push back (i)\n"
         << " Pop back (d)\n"
         << " Front (f)\n"
         << " Back (b)\n"
         << " Remove (e)\n"
         << " Reverse (r)\n"
         << " Print (p)\n"
         << " Fine (s)\n";
    cin >> res;
    switch (res) {
      case 'u':
        cout << "Val? : ";
        cin >> val;
        if (!push_front(l, val)) cout << "Lista piena!\n";
        break;
      case 'o':
        if (!pop_front(l)) cout << "Lista vuota!\n";
        break;
      case 'i':
        cout << "Val? : ";
        cin >> val;
        if (!push_back(l, val)) cout << "Lista piena!\n";
        break;
      case 'd':
        if (!pop_back(l)) cout << "Lista vuota!\n";
        break;
      case 'f':
        if (!front(l, val))
          cout << "Lista vuota!\n";
        else
          cout << "Front = " << val << endl;
        break;
      case 'b':
        if (!back(l, val))
          cout << "Lista vuota!\n";
        else
          cout << "Back = " << val << endl;
        break;
      case 'e':
        cout << "Val to remove? : ";
        cin >> val;
        if (!remove(l, val)) cout << "Valore non trovato!\n";
        break;
      case 'r':
        if (!reverse(l))
          cout << "Errore!\n";
        else
          cout << "Lista rovesciata." << endl;
        break;
      case 'p':
        print(l);
        break;
      case 's':
        break;
      default:
        cout << "Opzione errata\n";
    }
  } while (res != 's');
}
