#include <iostream>

using namespace std;

char* strstr(char s[], char t[]);

int main(int argc, char const *argv[]) {
  char a[] = "ciao mi chiamo filippo";
  char* p;
  p = strstr(a, "mi");

  if (p == NULL)
    cout << "il puntatore punta a NULL, quindi il carattere non è presente nella stringa." << endl;
  else {
    cout << "Il puntatore punta all'indirizzo [" << (long)p << "] che contiene il valore " << *p << endl;
    cout << "stampo cout << p: " << p << endl;
  }

  return 0;
}

char* strstr(char s[], char t[]){
  char* res = NULL;
  bool uguale = true;
  for (int i=0; s[i]!='\0' && res == NULL; i++){
    for(int j=0; t[j]!='\0'; j++){
      if(s[i+j] != t[j])
        uguale = false;
    }
    if (uguale) res = &s[i];
  }
  return res;
}
