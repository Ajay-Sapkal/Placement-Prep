#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int st, int end){

    int idx = st - 1;
    for (int j = st; j < end; j++)
    {
        if (nums[j] < nums[end])    
        {
            idx++;
            swap(nums[j], nums[idx]);
        }
        
    }
    idx++;
    swap(nums[end], nums[idx]);
    return idx;
}

void quick_sort(vector<int>& nums, int st, int end){

    if(st >= end) return;
    
    int p = partition(nums, st, end);

    quick_sort(nums, st, p-1);
    quick_sort(nums, p+1, end);

}
int main()
{
    vector<int> vec = {12, 3, 35, 8, 17, 23};
    quick_sort(vec, 0, vec.size()-1);

    for (int val : vec)
    {
        cout << val << " ";
    }
    cout<<endl;   
    return 0;
}