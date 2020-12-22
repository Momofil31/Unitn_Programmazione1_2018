#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const double e = 2.718;

double funzione(double x){
    double risultato;
    if (x<=0)
        risultato = pow(-x, 3.0);
    else
        risultato = pow(e, x-1.0);

    return risultato;
}

int main () {
    for (double i=-10.0; i<=10.0; i=i+1){
        cout << "f(" << i << ") = " << funzione(i) << endl;
    }
	return 0;
}
