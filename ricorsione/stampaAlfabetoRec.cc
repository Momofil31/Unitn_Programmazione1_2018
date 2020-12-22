// implementare la funzione stampa che ricever in ingresso due caratteri dell'alfabeto e stampa
//  tutte le lettere tra di essi estremi compresi
// stampa ricorsiva

#include <iostream>

using namespace std;

void stampa(char a, char b);


int main () {
	char a, b;
	do{
		cout <<"Introdurre la prima e ultima lettera da stampare: ";
		cin >> a >> b;
	} while (a < 'a' || b > 'z' || a >b );
	stampa(a, b);
	return 0;
}


void stampa(char a, char b){
	if (a > b){
		cout << endl;
	} else {
		cout << a;
		stampa(++a, b);
	}
}
