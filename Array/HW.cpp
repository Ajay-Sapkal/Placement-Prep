#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// WAF to swap the max and min numbers of an array
void swap_Min_Max(int arr[], int size)
{
    int small = INT_MAX;
    int large = INT_MIN;
    int m,n;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
            m = i;
        }
        if (arr[i] > large)
        {
            large = arr[i];
            n = i;
        }
        
    }
    swap(arr[m], arr[n]);
}

//Print only unique values 
// E.g. arr = 1 2 3 1 2 3 4   ---> print 4 only
void print_unique(int arr[], int size){

    bool unique;
    for (int i = 0; i < size; i++)
    {
        unique = true;
        for (int j = 0; j < 5; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                unique = false;
                // cout << arr[i] << " not unique\n";
            }
            
        }
        if (unique)
        {
            cout << arr[i] << " ";
        }
        
    }
    
}

//print common values from two array
void print_common(int arr1[], int arr2[], int s1, int s2){

    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";

            }
            
        }
        
    }
    
}

int main()
{
    int arr[6] = {1, 3 ,5 ,7 ,9 ,6};

    // swap_Min_Max(arr, 5);    

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    

    // print_unique(arr, 7);

    int arr2[5] = {2, 3, 8, 4, 7};
    print_common(arr, arr2, 6, 5);
    return 0;
}