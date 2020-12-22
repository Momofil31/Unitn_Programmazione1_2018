#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int a, b, c;

	cout << "Inserisci i coefficienti a, b, c dell'equazione di secondo grado" << endl;
	cin >> a >> b >> c;

	int delta = b*b - 4*a*c;

	if (delta < 0) {
		cout << "L'equazione non ha soluzioni reali." << endl;
	} else if (delta == 0) {
		cout << "Il discriminante è nullo quindi esiste un'unica soluzione reale x=" << -b/(2*a) << endl;
	} else {
		cout << "Le due soluzioni reali sono x=" << (-b-sqrt(delta))/(2*a) << " e x=" << (-b+sqrt(delta))/(2*a) << endl;
	}
	return 0;
}
