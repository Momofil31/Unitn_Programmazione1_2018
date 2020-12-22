#include <iostream>

using namespace std;

const int DIM = 'z'-'A';

int main(int argc, char const *argv[]) {
  int occorrenze[DIM] = {};
  char ch;


  while (cin.get(ch) && ch != '\0') {
    if((ch > 'a' && ch < 'z') || (ch > 'A' && ch < 'Z') ){
      occorrenze[ch-'A']++;
    }
  }

  for (int i = 0; i < DIM; i++) {
    cout << "occorrenze[" << (char)(i+'A') << "] = " << occorrenze[i] << endl;
  }
  return 0;
}
