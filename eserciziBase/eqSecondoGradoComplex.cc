#include <iostream>
#include <cmath>

using namespace std;

struct complesso {
	float x;
	float y;
};

int main (){
	int a, b, c;

	cout << "Inserisci i coefficienti a, b, c dell'equazione di secondo grado" << endl;
	cin >> a >> b >> c;

	int delta = b*b - 4*a*c;

	if (delta < 0) {
		complesso sol1;
		complesso sol2;
		sol1.x = float(-b)/(2*a);
		sol1.y = -sqrt(-1*delta)/(2*a);
		sol2.x = float(-b)/(2*a);
		sol2.y = sqrt(-1*delta)/(2*a);

		cout << "Le soluzioni esistono nell'insieme dei complessi ed sono x=";
		cout << sol1.x << sol1.y << "i e x=";
		cout << sol2.x << "+" << sol2.y << "i" << endl;

	} else if (delta == 0) {
		float sol = -b/(2*a);
		cout << "Il discriminante è nullo quindi esiste un'unica soluzione reale x=" << sol << endl;
	} else {
		float sol1 = (-b-sqrt(delta))/(2*a);
		float sol2 = (-b+sqrt(delta))/(2*a);
		cout << "Le due soluzioni reali sono x=" << sol1 << " e x=" << sol2 << endl;
	}
	return 0;
}
