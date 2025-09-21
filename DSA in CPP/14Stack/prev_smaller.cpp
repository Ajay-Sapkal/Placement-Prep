#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void previous_smaller_element(vector<int>& nums, vector<int>& result) {
    stack<int> st;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= nums[i])
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
    vector<int> vec = {3, 1, 0, 8, 6};
    vector<int> result(vec.size(), -1);
    previous_smaller_element(vec, result);
    for (int pse : result) {
        cout << pse << " ";
    }
    cout << endl;
    return 0;
}