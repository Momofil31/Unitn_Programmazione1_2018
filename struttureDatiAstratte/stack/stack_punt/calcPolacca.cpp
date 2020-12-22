#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

int main(){
    char * input;
    stack operandi;
    float a, b;
    
    do {
        cout << "Inserire operando o operatore: ";
        cin >> input;
        if (strcmp(input, "+") == 0) {
                top(operandi, a);
                pop(operandi);
                top(operandi, b);
                pop(operandi);
                float res = b+a;
                push(operandi, res);
                cout << res << endl;
        } else 
            if(strcmp(input, "-") == 0) {
                top(operandi, a);
                pop(operandi);
                top(operandi, b);
                pop(operandi);
                float res = b-a;
                push(operandi, res);
                cout << res << endl;
        } else 
            if (strcmp(input, "*") == 0) {
                top(operandi, a);
                pop(operandi);
                top(operandi, b);
                pop(operandi);
                float res = b*a;
                push(operandi, res);
                cout << res << endl;
        } else 
            if (strcmp(input, "/") == 0) {
                top(operandi, a);
                pop(operandi);
                top(operandi, b);
                pop(operandi);
                float res = b/a;
                push(operandi, res);
                cout << res << endl;
        } else {
                push(operandi, atof(input));
        }
    } while (strcmp(input, "c") != 0);
    
    return 0;
}