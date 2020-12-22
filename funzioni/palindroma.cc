#include <iostream>

using namespace std;

bool palindroma();

int main(){
  cout << "Inserisci la parola da verificare ";
  if (palindroma())
    cout << "La parola è palindroma.";
  else
    cout << "La parola non è palindroma.";
  return 0;
}

bool palindroma(){
  bool ris = false;
  char x, y;
  cin.get(x);
  if(x == '.')
    ris = true;
  else if (palindroma()){
    cin.get(y);
    ris = (x == y);
  }
  return ris;
}
