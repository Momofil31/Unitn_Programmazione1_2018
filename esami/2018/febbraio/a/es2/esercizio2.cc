#include <iostream>

using namespace std;

const int DIM = 81;

// Dichiarare qui sotto la funzione estrai
char* estrai(const char stringa[]);
void estrai_ric(const char stringa[], int i_in, char output[], int i_out);

int main () {
   char stringa[DIM], *estratta, risposta;
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
  // Definire qui sotto la funzione estrai

char* estrai(const char stringa[]) {
  //allocazione dinamica stringa output
  char*  output = new char [DIM];
  //chiamata alla funzione ricorsiva
  estrai_ric(stringa, 0, output, 0);
  return output;
}

void estrai_ric(const char stringa[], int i_in, char output[], int i_out) {
  //caso base
  if (i_in >= DIM || stringa[i_in] == '\0'){
    output[i_out] = '\0';
  } else {
    if (stringa[i_in] >= 'A' && stringa[i_in] <= 'Z') {
      output[i_out] = stringa[i_in];
      i_out++;
    }
    estrai_ric(stringa, i_in+1, output, i_out);
  }
}
