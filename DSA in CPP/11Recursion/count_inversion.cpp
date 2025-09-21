#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &nums, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    int invCount = 0;

    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }
    while (j <= end)
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
        nums[k + st] = temp[k];
    }

    return invCount;
}
// merge sort
int merge_sort(vector<int> &nums, int st, int end)
{

    if (st < end)
    {
        int mid = st + (end - st) / 2;

        int left_count = merge_sort(nums, st, mid);
        int right_count = merge_sort(nums, mid + 1, end);

        int count = merge(nums, st, mid, end);

        return left_count + right_count + count;
    }

    return 0;
}

int main()
{
    vector<int> vec = {1, 3, 5, 10, 2, 6, 8, 9};
    int count = 0;
    cout<<merge_sort(vec, 0, vec.size()-1)<<endl;
    
      
    return 0;
}