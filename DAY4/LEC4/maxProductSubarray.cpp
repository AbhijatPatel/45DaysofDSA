#include <bits/stdc++.h>
using namespace std;

//brute  force
// int maxProductSubarr(vector<int> & arr, int n){

//     int ans = INT_MIN;

//     for(int i=0;i<n;i++){
//         int product = 1;

//         for(int j=i;j<n;j++){
//             product *= arr[j];
//             ans = max(ans,product);
//         }
//     }
//     return ans;
// }

//optimized approach

int maxProductSubarr(vector<int> & arr, int n){
    
    int prefix = 1;
    int suffix = 1;
    
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        if(prefix == 0)
        prefix =1;

        if(suffix == 0)
        suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-i-1];

        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5,0};
    
    cout << maxProductSubarr(arr,arr.size());
    return 0;
}