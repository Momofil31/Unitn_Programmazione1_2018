#include <iostream>
#include <cmath>

using namespace std;

void ruota(int& a, int& b, int& c){
    int temp = a;
    a = b;
    b = c;
    c = temp;
    return;
}

int main () {
    int x, y, z;
    cout << "Inserisci tre interi: ";
    cin >> x >> y >> z;

    ruota(x, y, z);

    cout << x << '\t' << y << '\t' << z << endl;
	return 0;
}
