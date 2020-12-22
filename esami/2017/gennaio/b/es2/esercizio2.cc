#include <iostream>

using namespace std;

const int DIM = 80;

char* estrai(const char input[]);
void estrai_rec(const char input[], int i_input, char output[], int i_output);
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

char* estrai(const char input[]) {
  //allocazione dinamica stringa output
  char* output = new char [DIM];
  //chiamata alla funzione ricorsiva che estrae
  estrai_rec(input, 0, output, 0);

  return output;
}

void estrai_rec(const char input[], int i_input, char output[], int i_output) {
  //caso base
  if (input[i_input] == '\0' || i_input == DIM) {
    output[i_output] = '\0';
  } else {
    //se il carattere considerato e' una lettera minuscola
    if (input[i_input] >= 'a' && input[i_input] <= 'z') {
      output[i_output] = input[i_input];
      i_output++;
    }
    //chiamata ricorsiva
    estrai_rec(input, i_input+1, output, i_output);
  }
}
