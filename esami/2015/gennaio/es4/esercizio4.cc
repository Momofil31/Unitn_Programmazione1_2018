#include <iostream>
using namespace std;

long long fib(int n);

int main(int argc, char const *argv[]) {
  int n;
  cout << "n? (n >= 0): ";
  cin >> n;
  for (int i=0; i<=n; i++) {
    cout << "f(" << i << ") = " << fib(i) << endl;
  }
  return 0;
}


long long fib(int n){
  long long res;
  if (n<=1) {
    res = 1;
  } else {
    res = fib(n-1) + fib(n-2);
  }
  return res;
}
