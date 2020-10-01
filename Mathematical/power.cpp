// C++ program to change all char from lower to uppper
#include <iostream> 
using namespace std; 

// given double x and power index n,
// calculate x^n
double power(double x, int n) {        
    double result = 0;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else if (n == -1)
        return 1/x;
    
    double val = myPow(x, n/2);
    if (n % 2 == 0)
        result = val * val;
    else if (n % 2 == 1)
        result = val * val * x;
    else
        result = 1/x * val * val;
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
