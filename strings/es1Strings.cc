#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  char ch;
  int consonanti = 0;
  int vocali = 0;
  while (cin.get(ch) && ch != '\0') {
    switch (ch) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        vocali++;
        break;
      default:
        if(ch > 'A' && ch < 'z'){
          consonanti++;
        }
        break;
    }
  }
  cout << "Consonanti: " << consonanti << endl;
  cout << "Vocali: " << vocali << endl;

  return 0;
}
