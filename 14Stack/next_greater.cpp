#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void next_greater_element(vector<int>& nums, vector<int>& result) {
    stack<int> st;
    int n = nums.size();

    for (int i = n-1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = st.top();
        }
        st.push(nums[i]);
        
    }
    
  
}

int main()
{
    vector<int> vec = {6, 8, 0, 1, 3};
    vector<int> result(vec.size(), -1);
    next_greater_element(vec, result);
    for (int nge : result) {
        cout << nge << " ";
    }
    cout << endl;
    return 0;
}