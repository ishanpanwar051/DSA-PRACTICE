#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if(n == 0) return 1; 
    
    
    if(n < 0) {
        x = 1 / x;
        n = -n;
    }
    
    double half = myPow(x, n / 2);
    
    if(n % 2 == 0) {
        return half * half;
    } else {
        return half * half * x;
    }
}

int main() {
    cout << myPow(2.0, 10) << endl;   
    cout << myPow(2.1, 3) << endl;    
    cout << myPow(2.0, -2) << endl;   
    return 0;
}
