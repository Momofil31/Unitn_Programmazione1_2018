#include <iostream>
#include <cstring>

using namespace std;

int strcmp(char s[], char t[]);

int main(int argc, char const *argv[]) {
  char key[] = "apple";
    char buffer[80];
    do {
       cout << "Guess my favorite fruit? ";
       cin >> buffer;
    } while (strcmp (key, buffer) != 0);
    cout << "Correct answer!" << endl;
}

int strcmp(char s[], char t[]){
  int res = 0;
  int i = 0;
  while (s[i] == t[i] && s[i]!='\0') {
    i++;
  }
  res = s[i] - t[i];
  return res;
}
