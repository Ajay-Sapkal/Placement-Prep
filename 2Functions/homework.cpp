#include <iostream>
using namespace std;


//check if number is prime or not

bool isprime(int n){

    if (n <= 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= n/2; i++)
        {
            if (n%i == 0)
            {
                return false;
            }
            
        }

        return true;
    }
}

//print all prime numbers from 2 to N

void printPrimeNum(int n){

    if (n >= 2) cout << 2 << " ";
    
    for (int i = 3; i <= n; )
    {
        if (isprime(i))
        {
            cout << i << " ";
        }
        i = i + 2;
    }
    return ;
}

// Print nth Fibonacci

void Fibonacci(int n){

    int a, b, temp;
    a = 0;
    b = 1;

    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            cout << i << " ";
        }
        else
        {
            temp = a;
            a = b;
            b = temp + a;
            cout << b << " ";
        }
    }
    
    return ;
}
int main() {

    Fibonacci(8);
    return 0;
}