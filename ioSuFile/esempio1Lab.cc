#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (int argc, char * argv[])
{
  fstream myin;
  char c;

  if (argc<2) {
    cout << "Usage: ./a.out <sourcefile> <sourcefile2> <sourcefileN> \n";
    exit(EXIT_FAILURE);
  }

  for(int i=1; i<argc; i++){
    myin.open(argv[i],ios::in);
    if (myin.fail()) {
       cerr << "Il file " << argv[i] << " non esiste\n";
    }
    while(myin.get(c)){
      cout.put(c);
    }
    myin.close();
  }
  return 0;
}
