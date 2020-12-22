#include <iostream>

using namespace std;

char* strrchr(char s[], int c);

int main(int argc, char const *argv[]) {
  char a[] = "ciao mi chiamo filippo";
  char* p;
  p = strrchr(a, 'i');

  if (p == NULL)
    cout << "il puntatore punta a NULL, quindi il carattere non è presente nella stringa." << endl;
  else {
    cout << "Il puntatore punta all'indirizzo [" << (long)p << "] che contiene il valore " << *p << endl;
    cout << "stampo cout << p: " << p << endl;
  }

  return 0;
}

char* strrchr(char s[], int c){
  char* res = NULL;
  int lung = 0;
  while (s[lung] != '\0') {
    ++lung;
  }
  for (int i = lung; i>=0; i--) {
    if(s[i] == c)
      res = &s[i];
  }
  return res;
}
