#include <iostream>

using namespace std;

char* strchr(char s[], int c);

int main(int argc, char const *argv[]) {
  char a[] = "ciao mi chiamo filippo";
  char* p;
  p = strchr(a, 'i');

  if (p == NULL)
    cout << "il puntatore punta a NULL, quindi il carattere non è presente nella stringa." << endl;
  else {
    cout << "Il puntatore punta all'indirizzo [" << (long)p << "] che contiene il valore " << *p << endl;
    cout << "stampo cout << p: " << p << endl;
  }

  return 0;
}

char* strchr(char s[], int c){
  char* res = NULL;
  for (int i = 0; s[i]!='\0'; i++) {
    if(s[i] == c)
      res = &s[i];
  }
  return res;
}
