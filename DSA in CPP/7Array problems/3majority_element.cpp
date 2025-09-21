//MJ(majority element) is the element which apears more that n/2 time in array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//brute force approach
//check the frequency of each element
int b_mj(vector<int>& nums){
    int n = nums.size();
    int f;
    for (int val: nums){
        f = 0;
        for (int val2: nums){
            if (val == val2)
            {
                f++;
            }
        }
        if (f > n/2)
        {
            return val;
        }
    }

}

//Optimized method 
//first sort the array
int o_mj(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end()); // sort vector   
    int freq = 1, ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i-1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }
        if (freq > n/2)
        {
            return ans;
        }
        
    }
    
    return ans;
}


//moore's voting algorithm ---> best solution
int moore_mj(vector<int>& nums){
    int freq = 0, ans = 0;
    for (int val: nums){
        if (freq == 0)
        {
            ans = val;
        }
        if (ans == val)
        {
            freq++;
        }
        else { freq--; }

        
    }
    return ans;
}

int main() {

    vector<int> vec = {8, 8, 8, 6, 2, 8, 4, 8, 8, 5, 3};
    int mj = moore_mj(vec);
    cout << "MJ : " << mj << endl;

    for(int val: vec){
        cout << val << " ";
    }
    return 0;
}



