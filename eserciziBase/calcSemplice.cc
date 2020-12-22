#include <iostream>
#include <cmath>

using namespace std;

int main () {
    double op1, op2;
    char op;
    cout << "Immetti espressione del tipo \"operando1 operatore operando\": ";
    cin >> op1 >> op >> op2;
    switch (op) {
        case '+':
            cout << op1 + op2 << endl;
            break;
        case '-':
            cout << op1 - op2 << endl;
            break;
        case '*':
            cout << op1 * op2 << endl;
            break;
        case '/':
            cout << op1 / op2 << endl;
            break;
        default:
            cout << "errore!" << endl;
    }

	return 0;
}
