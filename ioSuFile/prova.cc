// fstream::open / fstream::close
#include <fstream>      // std::fstream

int main () {

  std::fstream fs;
  fs.open ("test.txt", 8 | 16 | 1);

  fs << " more lorem ipsum";

  fs.close();

  return 0;
}
