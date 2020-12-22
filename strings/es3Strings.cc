#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  char ch;
  bool isSeparator = false;


  while (cin.get(ch)) {
    if(ch == ' '){
      isSeparator = true;
    } else if(ch == '\n' || ch == '\t'){
      isSeparator = true;
    } else {
      if(isSeparator){
        cout << " " << ch;
        isSeparator = false;
      } else {
        cout << ch;
      }
    }
  }
  cout << endl;

  return 0;
}
