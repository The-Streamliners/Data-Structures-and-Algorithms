/* Nth fibonacci number using matrix exponentiation
Time complexity O(log(n))
Space complexity O(log(n))
*/

#include <iostream> 
using namespace std; 

void multiply_matrix(int fib[2][2], int mul[2][2]) 
{ 
    int a = fib[0][0] * mul[0][0] + fib[0][1] * mul[1][0]; 
    int b = fib[0][0] * mul[0][1] + fib[0][1] * mul[1][1]; 
    int c = fib[1][0] * mul[0][0] + fib[1][1] * mul[1][0]; 
    int d = fib[1][0] * mul[0][1] + fib[1][1] * mul[1][1]; 
    fib[0][0] = a; 
    fib[0][1] = b; 
    fib[1][0] = c; 
    fib[1][1] = d; 
} 

void exponent(int fib[2][2], int n) 
{ 
    if(n == 0 || n == 1) 
       return; 
    int mul[2][2] = {{1, 1}, {1, 0}}; 
    exponent(fib, n / 2); 
    multiply_matrix(fib, fib); 
    if (n % 2 != 0) 
        multiply_matrix(fib, mul); 
} 

int Fib(int n) 
{ 
    int fib[2][2] = {{1, 1}, {1, 0}}; 
    if(n == 0) 
        return 0; 
    exponent(fib, n - 1); 
    return fib[0][0]; 
} 

int main() 
{ 
    int n;
    cin>>n; 
    cout << Fib(n);  
    return 0; 
} 