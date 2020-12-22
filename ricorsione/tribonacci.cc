/*
  Dichiarare e definire la funzione tribonacci che implementa in modo ricorsivo
  una variante della sequenza di Fibonacci, dove
  T(0)= 0
  T(1) = 1
  T(2) = 1
  T(n) = T(n-1)+ T(n-2) + T(n-3)
  */


#include <iostream>
using namespace std;

int tribonacci(int n);

int main(int argc, char const *argv[]) {
  int n;
  cout << "Inserisci un numero: ";
  cin >> n;
  cout << "Tribonacci(" << n << ") = " << tribonacci(n) << endl;
  return 0;
}

int tribonacci(int n){
  int res;
  if (n <= 2){
    res = 1;
    if (n == 0)
      res = 0;
  }
  else
    res = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
  return res;
}
