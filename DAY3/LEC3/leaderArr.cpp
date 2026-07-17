#include <bits/stdc++.h>
using namespace std;

void findLeaderElm(vector<int> & arr, int n){
    int rightMaxElm=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(arr[i]> rightMaxElm){
            rightMaxElm=arr[i];
            ans.push_back(arr[i]);

        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
}

int main() {
    vector<int> arr ={10,22,12,3,0,6};

    findLeaderElm(arr,arr.size());
    return 0;
}