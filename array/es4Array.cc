#include <iostream>
using namespace std;

double prodScalare(const double a[], const double b[], int& n);
void leggiVettore(double a[], int& n);
bool ortogonali(const double a[], const double b[], int& n);

const int dim = 100;

int main(int argc, char const *argv[]) {
  int n1, n2;
  double a[dim];
  double b[dim];
  leggiVettore(a, n1);
  leggiVettore(b, n2);
  if (n1 == n2){
    if (ortogonali(a, b, n1))
      cout << "I vettori sono ortogonali." << endl;
    else
      cout << "I vettori non sono ortogonali." << endl;
  } else
      cout << "I due vettori hanno diversa dimensione";
  return 0;
}

void leggiVettore(double a[], int& n){
  cout << "Inserisci dimensione vettore: ";
  cin >> n;
  for(int i=0; i<n; i++){
    cout << "Inserisci l'elemento di posizione " << i+1 << ": ";
    cin >> a[i];
  }
}

bool ortogonali(const double a[], const double b[], int& n){
  bool res = false;
  if (prodScalare(a, b, n) == 0)
    res = true;
  return res;
}

double prodScalare(const double a[], const double b[], int& n){
  double res = 0;
  for(int i=0; i<n; i++){
    res += a[i]*b[i];
  }
  return res;
}
