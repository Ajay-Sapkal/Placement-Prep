#include <iostream>
#include <vector>
using namespace std;

// Iterative Approach
int Bsearch(int target, vector<int> &arr)
{
    int st = 0, end = arr.size() - 1;
    int mid;
    while (st <= end)
    {
        mid = st + (end - st)/2; // use this To prevent integer overflow when st and end are large values.
        if (target > arr[mid])
        {
            st = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

//recursive 
int B_search(vector<int> &arr, int target, int st, int end){

    if (st > end)
    {
        return -1;
    }
    
    int mid = st + (end - st)/2;

    if (target > arr[mid])
    {
        B_search(arr, target, mid+1, end);
    }
    else if (target < arr[mid])
    {
        B_search(arr, target, st, mid-1);
    }
    else {
        return mid;
    }    

}
int main()
{

   
    vector<int> vec = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    
    int target = 7;
    int st = 0, end = vec.size() - 1;
    // cout << Bsearch(target, vec) << endl;
    cout << B_search(vec,target,st,end) << endl;

    return 0;
}
