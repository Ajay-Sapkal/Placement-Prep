#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " value: ";
        cin >> arr[i];
    }
    
    cout << "array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    int start = 0, end = 4;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    
    cout << "\nReversed array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}