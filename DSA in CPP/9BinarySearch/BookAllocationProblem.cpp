#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<int> arr, int n, int m, int mid){
    int stu = 1, pages = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > mid) return false;

        if((pages + arr[i]) <= mid){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }
    if(stu <= m) return true;
    else return false;
}

int Book_Allocation(vector<int>& arr, int n, int m){
    int st = 0, end = 0, mid,ans = -1;

    for(int i = 0; i < n; i++){
        end += arr[i];
    }

    while(st <= end){
        mid = st + (end-st)/2;

        if(isvalid(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {2,1,3,4};
    int n = 4, m = 2;

    cout<< Book_Allocation(arr,n,m)<<endl;
    return 0;
}