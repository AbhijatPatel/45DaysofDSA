#include <bits/stdc++.h>
using namespace std;

int findSingleOcc(vector<int> & arr, int n){
    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    vector<int> arr = {4,1,2,1,2};

    cout << findSingleOcc(arr,arr.size());
    return 0;
}