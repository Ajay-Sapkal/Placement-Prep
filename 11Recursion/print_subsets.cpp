#include <iostream>
#include <vector>
using namespace std;

void print_subsets(vector<int>& nums, vector<int>& ans, int i)
{
    if (i == nums.size())
    {
        cout << "{ ";
        for (int num : ans)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    ans.push_back(nums[i]);
    print_subsets(nums, ans, i + 1);

    ans.pop_back();

    print_subsets(nums, ans, i + 1);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    print_subsets(arr, ans, 0);
    return 0;
}