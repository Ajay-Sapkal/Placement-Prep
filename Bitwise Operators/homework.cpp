#include <iostream>
#include <cmath>
using namespace std;

// figure out how to find if a number is power of 2 without any loop
bool hm(int n){
    if (n <= 0)
    {
        return false;
    }

    int logvalue = log2(n);

    return pow(2, logvalue) == n;
    
}

//reverse an integer 
int reverse(int n){
    int revNum = 0;
    while (n > 0)
    {
        revNum = revNum * 10 + n % 10;
        n /= 10;
    }

    return revNum;
    
}

int main() {

    int n = 32;

    cout << reverse(32) << endl;
    cout << reverse(254) << endl;
    cout << reverse(25478) << endl;
    cout << reverse(21456) << endl;

    
    return 0;
}