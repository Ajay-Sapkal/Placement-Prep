#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
        
    }
    
}

void selection_sort(vector<int>& arr){
    int n = arr.size();

    for(int i = 0; i < n - 1; i++){
        int smallest_index = i;
        for (int  j = i + 1; j < n; j++)
        {
            if (arr[smallest_index] > arr[j])
            {
                smallest_index = j;
            }
        }
        
        swap(arr[smallest_index], arr[i]);
    }

}

void insertion_sort(vector<int>& arr){
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i-1;
        while (prev >=0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--; 
        }
        arr[prev + 1] = curr;
        
    }
    
}



int main()
{
    vector<int> arr = {5, 2, 3, 6, 7, 1, 9};

    insertion_sort(arr);

    for(int val: arr){
        cout << val << " ";
    }
    
    return 0;
}