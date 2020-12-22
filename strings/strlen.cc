#include <iostream>

using namespace std;

int strlen(char s[]);

int main(int argc, char const *argv[]) {
  char a[] = "ciao mi chiamo filippo";
  int lunghezza;
  lunghezza = strlen(a);
  cout << lunghezza;
  return 0;
}

int strlen(char s[]){
  int res = 0;
  while (s[res] != '\0') {
    ++res;
  }
  return res;
}
