#include <iostream>
#include <cstring>

using namespace std;

void strcat(char s[], char t[]);

int main(int argc, char const *argv[]) {
  char str[80];
  strcpy (str,"these ");
  strcat (str,"strings ");
  strcat (str,"are ");
  strcat (str,"concatenated.");
  puts (str);
  return 0;
}

void strcat(char s[], char t[]){
  int lungS = strlen(s);
  for (int i = 0; i!='\0'; i++) {
    s[lungS+i] = t[i];
  }
}
