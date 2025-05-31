#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    vector<int> vec1(5, 0); // creates the vector of size 5 and initialize each index with value '0'
    // cout << vec[0] << endl;

    vec.push_back(4);
    vec.push_back(5);
    vec.pop_back(); 
    vec.push_back(6);
   

    cout << "size = " << vec.size() << endl;
    cout << "capacity = " << vec.capacity() << endl;
    for(int val : vec){
        cout << val << " " ;
    }

    return 0;
}