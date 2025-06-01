//Maximum Subarray sum

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


int main() {

    int n = 7;
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};


    ////Print all subarray's 
    // for (int st = 0; st < n; st++)
    // {
    //     for (int end = st; end < n; end++)
    //     {
    //         cout << "{";
    //         for (int i = st; i <= end; i++)
    //         {
    //             cout << arr[i] << " ";
    //         }
    //         cout << "} ";
    //     }
    //     cout << endl;
    // }
    
    //Brute force approach to find max sum
    // int maxSum = INT_MIN;
    // for (int st = 0; st < n; st++)
    // {
    //     int currSum = 0;
    //     for (int end = st; end < n; end++)
    //     {
    //         currSum += arr[end];
    //         maxSum = max (currSum, maxSum);
    //     }
    // }
    // cout << "Max sum is : " << maxSum << endl; 
    
    //Kadane's algorithm
    int maxSum = INT_MIN , currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << "Max sum is : " << maxSum << endl; 
    
    return 0;
}