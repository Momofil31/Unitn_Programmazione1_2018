#include <iostream>
#include <cstring>

using namespace std;

void strncat(char s[], char t[], int n);

int main(int argc, char const *argv[]) {
  char str1[20];
  char str2[20];
  strcpy (str1,"To be ");
  strcpy (str2,"or not to be");
  strncat (str1, str2, 6);
  puts (str1);
  return 0;
}

void strncat(char s[], char t[], int n){
  int lungS = strlen(s);
  for (int i = 0; i<n; i++) {
    s[lungS+i] = t[i];
  }
}
