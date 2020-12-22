#include <iostream>

using namespace std;

void strncpy(char s[], char t[], int n);

int main(int argc, char const *argv[]) {
  char s1[] = "ABCDEFG";
  char s2[] = "XYZ";
  cout << "Before strncpy(s1,s2,2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  //cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;
  strncpy(s1,s2,2);
  //strncpy(s1,s2,4);  //RS: che succede in questo caso?:
  cout << "After strncpy(s1,s2,2):\n";
  cout << "\ts1 = [" << s1 << "], length = " << strlen(s1) << endl;
  cout << "\ts2 = [" << s2 << "], length = " << strlen(s2) << endl;
  return 0;
}

void strncpy(char s[], char t[], int n){
  for (int i = 0; i<n; i++) {
    s[i] = t[i];
  }
}
