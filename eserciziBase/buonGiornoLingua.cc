#include <iostream>
#include <cmath>

using namespace std;

int main (){
	char carattere;

	cout << "Inserisci un carattere corrispondente a una lingua: " << endl;
	cout << "i = italiano" << '\t' << "e = inglese" << endl;
	cout << "s = spagnolo" << '\t' << "j = giapponese" << endl;
	cout << "f = francese" << '\t' << "t = tedesco" << endl;
	cin >> carattere;

	switch (carattere) {
	case 'i':
		cout << "Buon giorno!" << endl;
		break;
	case 'e':
		cout << "Good Morning!" << endl;
		break;
	case 's':
		cout << "Buenos dias!" << endl;
		break;
	case 'j':
		cout << "Ohayo gozaimasu" << endl;
		break;
	case 'f':
		cout << "Bonjour" << endl;
		break;
	case 't':
		cout << "Guten Tag" << endl;
		break;
	}
	return 0;
}
