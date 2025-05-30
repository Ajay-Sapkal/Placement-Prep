#include <iostream>
using namespace std;

//Decimal to binary
int dec_to_binary(int n){
    int ans = 0, pow = 1, rem;

    while (n > 0)
    {
        rem = n%2;
        n = n/2;
        
        ans += rem * pow;
        pow = pow * 10;
    }

   return ans;
}

//Binary to Decimal
int binary_to_deci(int n){
    int rem, ans = 0, pow = 1;

    while (n > 0)
    {
        rem = n%10;
        ans += rem * pow;

        pow *= 2;
        n /= 10;
    }
    
    return ans;
}
int main() {

    cout << binary_to_deci(101) << endl;
    return 0;
}