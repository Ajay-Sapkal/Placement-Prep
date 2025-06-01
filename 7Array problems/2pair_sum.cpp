#include <iostream>
#include <vector>
using namespace std;

// return the pair in sorted array which sum is equal to target 
vector<int> pair_sum(vector<int>& nums, int target){
    
    int i = 0, j = nums.size() - 1;
    int ps = 0;
    vector<int> ans;
    while (i < j)
    {
        ps = nums[i] + nums[j];
        if (ps == target)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }
        else if (ps > target)
        {
            j--;
        }
        else
        {
            i++;
        }
        
        // return ans;
    }
    
    
}
int main() {

    vector<int> vec = {1, 3, 6, 7, 9, 12, 13, 16, 23};
    
    vector<int> ans = pair_sum(vec, 20);

    for (int val: ans){
        cout << val << " ";
    }
    return 0;
}