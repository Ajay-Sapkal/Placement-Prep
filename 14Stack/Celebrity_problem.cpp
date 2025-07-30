#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Returns the index of the celebrity if present, else -1
int findCelebrity(vector<vector<int>>& M, int n) {

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    
    while (st.size() > 1)
    {
        int i = st.top();
        st.pop();

        int j = st.top();
        st.pop();
        if (M[i][j] == 1)
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
        
    }

    int ans = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i == ans)
        {
            continue;   
        }
        
        if(M[i][ans] == 0 || M[ans][i] == 1) return -1;
    }

    return ans;
}

int main()
{
    // Sample 2D array (matrix) for celebrity problem
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = M.size();
    // Call the empty function (for practice)
    int celeb = findCelebrity(M, n);
    cout << "Celebrity index: " << celeb << endl;
    return 0;
}