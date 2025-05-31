#include <iostream>
using namespace std;


//Calculate the sum of digits of number
int sumOfDigits(int n){
    int sum = 0;
    while (n > 0)
    {
        sum = sum + n % 10 ;
        n = n/10;
    }
    return sum;
    
}

//factorial of number
int factorial(int n){
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

// Calculate nCr binomial coefficient for n & r
float nCr(int n, int r){

    int n_fact = factorial(n);
    int r_fact = factorial(r);
    int nr_fact = factorial(n-r);

    int sol = n_fact/(r_fact*nr_fact);

    return sol;
    
}
int main() {

    cout << nCr(8 ,2 );
    return 0;
}