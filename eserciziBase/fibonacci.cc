#include <iostream>
#include <cmath>

using namespace std;

int main (){
    int N = 20;
    int count = 0;
    int fibA = 0;
    int fibB = 1; //b=a+1
    int fib;
    for(int i=0; i<N; i++){
        fib = fibA + fibB;
        count++;
        cout << fib << " " << count << endl;
        fibA = fibB;
        fibB = fib;
    }


	return 0;
}
