#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool isPrimo(int numero){
	bool primo = true;
	for(int i=2; i<=sqrt(numero); i++){
		if(numero%i==0)
			primo = false;
	}
	return primo;
}

int main (){
	int N, count, i;

	fstream myout;
	myout.open("output.txt", ios::out);

	cout << "Quanti numeri primi vuoi? (N) ";
	cin >> N;
	count = 0;
	i = 1;
	while(count<N){
		if (isPrimo(i)){
			myout << i << endl;
			count++;
		}
		i++;
	}
	myout.close();
	return 0;
}
