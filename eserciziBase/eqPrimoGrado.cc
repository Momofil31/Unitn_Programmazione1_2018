#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int a, b;

	cout << "Inserisci i coefficienti a e b dell'equazione di primo grado" << endl;
	cin >> a >> b;

	if (a != 0) {
		cout << "la soluzione è: " << (-b)/a << endl;
	} else
	   if (b == 0) {
           cout << "L'equazione e' indeterminata" << endl;
       } else {
           cout << "L'equazione è impossibile" << endl;
	      }

	return 0;
}
