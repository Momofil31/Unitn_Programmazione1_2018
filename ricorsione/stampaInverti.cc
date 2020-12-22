#include <iostream>

using namespace std;
void stampa_inverti();

int main(){
  cout << "Immetti la parola da invertire: ";
  stampa_inverti();
  cout << endl;
}

void stampa_inverti(){
  char a;
  cin.get(a);
  if (a != '\n'){
    stampa_inverti();
    cout << a;
  }
}
