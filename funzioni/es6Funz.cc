#include <iostream>
#include <cmath>

using namespace std;
const double pi = 3.14;
int areaPerimetroCerchio(double raggio, double& area, double& perimetro);


int main () {
    double x, area, perimetro;
    bool isCalcolato;
    cout << "Inserisci il raggio del cerchio: ";
    cin >> x;
    isCalcolato = areaPerimetroCerchio(x, area, perimetro);
    if (isCalcolato){
        cout << "L'area è: " << area << endl;
        cout << "Il perimetro è: " << perimetro << endl;
    }
	return 0;
}

int areaPerimetroCerchio(double raggio, double& area, double& perimetro){
    int isCalcolato = 0;
    if (raggio >= 0){
        area = pi * pow(raggio, 2.0);
        perimetro = 2*pi*raggio;
        isCalcolato = 1;
    }
    return isCalcolato;
}
