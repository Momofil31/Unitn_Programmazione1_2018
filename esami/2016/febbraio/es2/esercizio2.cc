#include <iostream>
#include <string>
using namespace std;
const char SEGNAPOSTO = '!';
const int DIMMAX = 40;


// Dichiarare qui sotto la funzione reverse_array
void reverse_array(char* array, int dim);
bool vocaleMinuscola(char ch);

int main (int argc, char* argv[]) {
  char input[DIMMAX];
  cout << "Introdurre stringa da invertire: ";
  cin >> input;
  // Assumiamo che sia sempre strlen(input) < DIMMAX
  reverse_array(input, strlen(input));
  cout << "Array invertito: " << input << endl;
  return 0;
}

void reverse_array(char* array, int dim) {
  if (dim>0) {
    if (vocaleMinuscola(array[0]) && vocaleMinuscola(array[dim-1])) {
      array[0] = array[dim-1] = SEGNAPOSTO;
    } else if (vocaleMinuscola(array[0])) {
      array[0] = array[dim-1];
      array[dim-1] = SEGNAPOSTO;
    } else if (vocaleMinuscola(array[dim-1])) {
      array[dim-1] = array[0];
      array[0] = SEGNAPOSTO;
    } else {
      char tmp = array[dim-1];
      array[dim-1] = array[0];
      array[0] = tmp;
    }
    reverse_array(array+1, dim-2);
  }
}

bool vocaleMinuscola(char ch) {
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
