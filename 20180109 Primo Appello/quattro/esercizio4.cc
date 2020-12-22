#include <iostream>
#include <iomanip>

using namespace std;

void stampaarray(const int V[],int n);
void leggiarray(int V[],int & n);
void intersezione(const int A[], int dima,
                  const int B[], int dimb,
                  int C[], int & dimc) ;

int main () {
   const int MAXDIM = 100;
   int A[MAXDIM] = {1,3,4,5,7,9,10,11,14,19,21,24};
   int dima = 12;
   int B[MAXDIM] = {0,1,2,4,5,6,8,11,12,13,15,19,22,23,24,27};
   int dimb = 16;
   int C[MAXDIM];
   int dimc;
   intersezione(A,dima,B,dimb,C,dimc);
   stampaarray(C,dimc);
   leggiarray(A,dima);
   leggiarray(B,dimb);
   intersezione(A,dima,B,dimb,C,dimc);
   stampaarray(C,dimc);
}

// Inserire le definizioni di intersezione, stampaarray e
// leggiarray qui sotto.
void stampaarray(const int V[],int n) {
  for (int i=0; i<n; i++) {
    cout << V[i] << " ";
  }
  cout << endl;
}

void leggiarray(int V[],int & n) {
  cout << "Inserire dimensione array: ";
  cin >> n;

  for (int i=0; i<n; i++) {
    cout << "Inserire elemento (int): ";
    cin >> V[i];
  }
}

void intersezione_rec(const int A[], int dima, const int B[], int dimb, int C[], int & dimc, int i_a, int i_b) {
  //opera sugli array finchè gli indici non hanno raggiunto la fine degli array a e b
  // <= perchè altrimenti non considera l'ultimo elemento
  if (i_a <= dima && i_b <= dimb ) {
    if (A[i_a] == B[i_b]) {
      //se trovo un elemento prensente sia in A che in B lo copio nell'array C e aumento la sua dimensione
      dimc++;
      C[dimc-1] = A[i_a];
      //aumento entrambi gli indici di A e B
      i_a++;
      i_b++;
    } else {
      //se l'elemento di A all'indice considerato è minore dell'elemento di B al rispettivo indice
      //aumento l'indice di A
      if (A[i_a] < B[i_b]) {
        i_a++;
      } else if (A[i_a] > B[i_b]) {
        //se l'elemento di A all'indice considerato è maggiore dell'elemento di B al rispettivo indice
        //aumento l'indice di B
        i_b++;
      }
    }
    //chiamata ricorsiva
    intersezione_rec(A, dima, B, dimb, C, dimc, i_a, i_b);
  }
}

void intersezione(const int A[], int dima, const int B[], int dimb, int C[], int & dimc) {
  //inizializzo la dimensione di C
  dimc = 0;
  //chiamata ricorsiva
  intersezione_rec(A, dima-1, B, dimb-1, C, dimc, 0, 0);
}
