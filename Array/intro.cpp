#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{

    // find samllest and largets number in array

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " value: ";
        cin >> arr[i];
    }

    // int min = arr[0], max = arr[0];
    // for (int i = 1; i < 5; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    //     if (arr[i] < min)
    //     {
    //         min = arr[i];
    //     }
    // }

    int smallest = INT_MAX;
    int largest= INT_MIN;
    for (int i = 0; i < 5; i++)
    {
        
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }
    
    
    // cout << "max: "<< max << "\nmin: "<< min ;
    cout << "max: "<< largest << "\nmin: "<< smallest ;

        return 0;
}