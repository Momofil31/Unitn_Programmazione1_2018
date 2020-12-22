#include <iostream>
#include "queue.h"

using namespace std;

int main ()
{
  char res;
  char val;
  queue q;

  init(q);
  do {
    cout << "\nOperazioni possibili:\n"
         << "Enqueue (e)\n"
         << "First (f)\n"
         << "Dequeue (d)\n"
         << "Print (p)\n"
         << "Exit (x)\n";
    cin >> res;
    switch (res) {
    case 'e':
      cout << "Valore: ";
      cin >> val;
      if (enqueue(q, val)==FALSE)
        cout << "Coda piena\n";
      break;
    case 'f':
      if (first(q, val)==FALSE)
        cout << "Coda vuota\n";
      else
        cout << "Val: " << val << endl;
      break;
    case 'd':
      if (dequeue(q)==FALSE)
        cout << "Coda vuota\n";
      break;
    case 'p':
      print(q);
      break;
    case 'x':
      break;
    default:
      cout << "Valore errato!\n";
    }
  } while (res != 'x');
  //deinit(q);
}
