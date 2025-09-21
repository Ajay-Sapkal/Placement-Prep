#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int st, int mid, int end){
    vector<int> temp; 
    int i = st, j = mid+1;

    while (i <= mid && j <= end)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        } 
    }
    while (j<= end)
    {
        temp.push_back(nums[j]);
        j++;
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    
    for (int k = 0; k < temp.size(); k++)
    {
        nums[st+k] = temp[k];
    }
    
    
}
//merge sort
void merge_sort(vector<int>& nums, int st, int end){

   
    
    if (st < end)
    {
        int mid = st + (end - st)/2;
 
        merge_sort(nums, st, mid);
        merge_sort(nums, mid+1, end);

        merge(nums, st, mid, end);
    }
    
    
}

int main()
{
    vector<int> vec = {12, 3, 35, 8, 17, 23};
    merge_sort(vec, 0, vec.size()-1);

    for (int val : vec)
    {
        cout << val << " ";
    }
    cout<<endl;   
    return 0;
}