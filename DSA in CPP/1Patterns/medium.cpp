#include <iostream>
using namespace std;

int main() {

    int n = 4;

    //Reverse Traingle Pattern
    // 1111
    //  222
    //   33
    //    4

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int k = n-i; k > 0; k--)
    //     {
    //         cout << i+1;
    //     }
    //     cout << endl;
    // }


    // Pyramid Pattern
    //      1
    //     121
    //    12321
    //   1234321   

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n-1-i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int k = 0; k < i+1; k++)
    //     {
    //         cout << k+1;
    //     }
    //     for (int m = i; m > 0; m--)
    //     {
    //         cout << m;
    //     }
    //     cout << endl;

    // }

    // Hollow diamond pattern
    //    *         
    //   * *
    //  *   *
    // *     *
    //  *   *
    //   * *
    //    * 
    //// top
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n-1-i; j++)
    //     {
    //         cout << " ";
    //     }
    //     cout<<"*";
    //     for (int k = 0; k < i*2 - 1 ; k++)
    //     {
    //         cout << " ";
    //     }
    //     if (i != 0)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    
    ////Bottom
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout<< " ";
    //     }
    //     cout << "*";
    //     for (int k = 0; k < 2*(n-2-i) - 1 ; k++)
    //     {
    //         cout << " ";
    //     }
    //     if (i != 2)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    

    // HOME WORK 
    // Butterfly Pattern 
    // for n=4         i        spaces
    // *      *        0           6 
    // **    **        1           4
    // ***  ***        2           2   
    // ********        3           0
    // ********        0           0       
    // ***  ***        1           2
    // **    **        2           4    
    // *      *        3           6    

    //top
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < (n-1-i)*2; k++)
        {
            cout << " ";
        }
        for (int m = 0; m < i+1; m++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    //Bottom
    for (int i = 0; i < n; i++)
    {
        for (int j = n-i; j > 0; j--)
        {
            cout << "*";
        }
        for (int k = 0; k < i*2; k++)
        {
            cout << " ";
        }
        for (int m = 0; m < n-i; m++)
        {
            cout << "*";
        }
        
        cout << endl;
    }
    


    return 0;
}