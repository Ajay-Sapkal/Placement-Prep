#include <iostream>
using namespace std;


// Calculate sum of numbers form 1 to N
int sumOfNumbers(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

//Calculate N factorial
int factorial(int n){
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int main() {

    cout << sumOfNumbers(10)<< endl;
    cout << factorial(1)<<endl;
    cout << factorial(0)<<endl;
    cout << factorial(5)<< endl;
    return 0;
}