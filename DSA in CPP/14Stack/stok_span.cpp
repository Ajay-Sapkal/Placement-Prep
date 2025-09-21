#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//generate a template empty function for stock span problem 
void stock_span(vector<int>& prices, vector<int>& spans) {
    stack<int> st;
    int n = prices.size();

    for (int i = 0; i < n; i++)
    {
        while (st.size() > 0 && prices[st.top()] <= prices[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            spans[i] = i + 1;
        }
        else
        {
            spans[i] = i - st.top();
        }
        
        st.push(i);
    }
    
}

int main()
{
    vector<int> vec = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans(vec.size(), 0);
    stock_span(vec, spans);
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;
    return 0;
}