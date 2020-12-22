#include <iostream>
#include <cmath>

using namespace std;
#define DIM 2

int main () {
    int matriceA[DIM][DIM];
    int matriceB[DIM][DIM];
    int prodotto[DIM][DIM];

    cout << "matriceA: " << endl;
    for (int i=0; i < DIM; i++){
        for (int j=0; j < DIM; j++){
            matriceA[i][j]=i;
            cout << matriceA[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "matriceB: " << endl;
    for (int i=0; i < DIM; i++){
        for (int j=0; j < DIM; j++){
            matriceB[i][j]=j;
            cout << matriceB[i][j] << '\t';
        }
        cout << endl;
    }

    //prodotto

    for (int i=0; i < DIM; i++){
        for (int j=0; j < DIM; j++){
            prodotto[i][j] = 0;
        }
    }
    cout << "prodotto: " << endl;
    for (int i=0; i < DIM; i++){
        for (int j=0; j < DIM; j++){
            for (int h=0; h < DIM; h++){
                    prodotto[i][j] += matriceA[i][h] * matriceB[h][j];
                }
            cout << prodotto[i][j] << '\t';
        }
        cout << endl;
    }


	return 0;
}
