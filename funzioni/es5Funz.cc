#include <iostream>
#include <cmath>

using namespace std;
const double pi = 3.14;
void areaCerchio(double raggio);


int main () {
    double x;
    cout << "Inserisci il raggio del cerchio: ";
    cin >> x;
    areaCerchio(x);

	return 0;
}

void areaCerchio(double raggio){
    double area;
    area = pi * pow(raggio, 2.0);
    cout << "L'area del cerchio è: " << area << endl;
}
