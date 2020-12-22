#include <iostream>
#include <cmath>

using namespace std;

int main (){
	bool risposta;
	cout << "Pensa a un numero, ti farò delle domande per indovinarlo. Rispondi solo si (1) o no (0)" << endl;
	cout << "E' maggiore di 3?" << endl;
	cin >> risposta;
	if (risposta) {
		cout << "E' maggiore di 5?" << endl;
		cin >> risposta;
		if (risposta) {
			cout << "Il numero a cui hai pensato è il 6?" << endl;
			cin >> risposta;
			if (risposta) {
				cout << "Ho indovinato!" << endl;
			} else {
				cout << "Il numero a cui hai pensato è il 7." << endl;
			}
		} else {
			cout << "Il numero a cui hai pensato è il 4?" << endl;
			cin >> risposta;
			if (risposta) {
				cout << "Ho indovinato!" << endl;
			} else {
				cout << "Il numero a cui hai pensato è il 5." << endl;
			}
		}
	} else {
		cout << "E' maggiore di 1?" << endl;
		cin >> risposta;
		if (risposta) {
			cout << "Il numero a cui hai pensato è il 2?" << endl;
			cin >> risposta;
			if (risposta) {
				cout << "Ho indovinato!" << endl;
			} else {
				cout << "Il numero a cui hai pensato è il 3." << endl;
			}
		} else {
			cout << "Il numero a cui hai pensato è lo 0?" << endl;
			cin >> risposta;
			if (risposta) {
				cout << "Ho indovinato!" << endl;
			} else {
				cout << "Il numero a cui hai pensato è l'1." << endl;
			}
		}
	}

	return 0;
}
