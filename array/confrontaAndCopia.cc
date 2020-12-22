#include <iostream>

using namespace std;

bool confronta(const char a[], int& n, const char b[], int& n2);
void copia(char a[], int& n1, const char b[], int& n2);

const int dim = 5;

int main(int argc, char const *argv[]) {
  int n = 5;
  char a[dim] = { 'a', 'b', 'c', 'd', 'e'};
  char b[dim];
  bool uguali = false;

  uguali = confronta(a, n, b, n);
  if(uguali){
    cout << "Gli array sono uguali." << endl;
  } else {
    cout << "Gli array sono diversi: copio gli array" << endl;
    copia(a, n, b, n);
    if(confronta(a, n, b, n)){
      cout << "Gli array ora sono uguali." << endl;
    }
  }
  return 0;
}

bool confronta(const char a[], int& n1,const char b[], int& n2){
  bool res = true;
  if(n1 == n2){
    for(int i=0; i<n1 && res==true; i++){
      if(a[i] != b[i]){
        res = false;
      }
    }
  } else {
    res = false;
  }
  return res;
}

void copia(char a[], int& n1, const char b[], int& n2){
  for(int i=0; i<n1; i++){
    a[i] = b[i];
  }
}
