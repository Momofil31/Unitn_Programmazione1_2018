#include <iostream>

using namespace std;

void strcpy(char s[], char t[]);

int main(int argc, char const *argv[]) {
  char s1[] = "ABCDEFG";
  char s2[] = "XYZ";
  cout << "Before strcpy(s1,s2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;
  strcpy(s1,s2);
  cout << "After strcpy(s1,s2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;
  return 0;
}

void strcpy(char s[], char t[]){
  for (int i = 0; t[i]!='\0'; i++) {
    s[i] = t[i];
  }
}
