#include <iostream>

using namespace std;

const int DIM = 80;

char* estrai(const char stringa[]);
void estrai_rec(char stringa_estratta[], const char stringa[], int i, int i_estr);

int main () {
  char stringa[DIM + 1], *estratta, risposta;
  do {
    cout << "Inserisci la stringa da controllare: ";
    cin >> stringa;

    estratta = estrai(stringa);
    cout << "La stringa estratta e’: " << estratta << endl;
    
    cout << "Vuoi inserire un’altra stringa? [s/n] ";
    cin >> risposta;
  } while (risposta != 'n' && risposta != 'N');
  return 0;
}

char* estrai(const char stringa[]) {
  char * stringa_estratta = new char[DIM+1];
  estrai_rec(stringa_estratta, stringa, 0, 0);

  return stringa_estratta;
}

void estrai_rec(char stringa_estratta[], const char stringa[], int i, int i_estr) {
  if (stringa[i] == '\0' || i == DIM) {
    stringa_estratta[i_estr] = '\0';
  } else {
    if (stringa[i] >= 'A' && stringa[i] <= 'Z') {
      stringa_estratta[i_estr] = stringa[i];
      i_estr++;
    }
    estrai_rec(stringa_estratta, stringa, i+1, i_estr);
  }
}
