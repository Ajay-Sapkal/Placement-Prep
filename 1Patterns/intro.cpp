#include <iostream>
using namespace std;

int main() {

    int n = 4;


    // Pattern 1
    // A B C D
    // A B C D
    // A B C D
    // A B C D
    // for (int i = 0; i < n; i++)
    // {
    //     char ch = 'A';
    
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << ch << " ";
    //       ch = ch + 1;
    //     }
    //     cout << endl;

    // }
    

    // Pattern 2
    // 1 2 3
    // 4 5 6
    // 7 8 9

    // int count = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << count << "  ";
    //         count++;
    //     }
    //     cout << endl;
    // }
   
    // Pattern 3
    // Triangle patter
    // *
    // * *
    // * * *
    // * * * *
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
        
    // }
    
    // Pattern 4
    // 1
    // 22
    // 333
    // 4444
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout << i +1 << " ";
    //     }
    //     cout << endl;
    // }

    
    // Pattern 5
    // 1
    // 12
    // 123
    // 1234

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i+1; j++)
    //     {
    //         cout << j+1<< " ";
    //     }
    //     cout << endl;
    // }
    
    // reverse triangle
    // 1 
    // 21
    // 321
    // 4321

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1 ; j > 0; j--)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl ;
    // }

    // char version
    // for (int i = 0; i < n; i++)
    // {
    //     char ch = 'A';
    //     for (int j = i ; j >= 0; j--)
    //     {   
    //         cout << char(ch+j) << " ";
    //     }
    //     cout << endl ;
    // }
    
    
    // Floyd's Traingle Pattern 
    // 1
    // 23
    // 456
    // int num = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }
    

    return 0;
}