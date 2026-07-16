#include <bits/stdc++.h>
using namespace std;

//brute force approach

// int maxSubarraySum(vector<int> & arr,int n,int k){
//     int maxLen = 0;

//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i; j < n; j++){
//             sum += arr[j];
//             if(sum == k){
//                 maxLen = max(maxLen,j-i+1);
//             }
//         }
//     }
//     return maxLen;
// }

//Better approach

//  int maxSubarraySum(vector<int> & arr,int n,int k){
//     int maxLen = 0;
//     int prefixSum = 0;

//     map<int,int> mp;

//     for(int i = 0; i < n; i++){
//         prefixSum += arr[i];

//         if(mp.find(prefixSum) == mp.end()){
//         mp[prefixSum] = i;
// }

//         if(prefixSum == k){
//             maxLen = max(maxLen,i+1);
//         }

//         else if(mp.find(prefixSum-k) != mp.end()){
//             int t = mp[prefixSum-k];
//             maxLen = max(maxLen, i-t);
//         }
//     }
//     return maxLen;
//  }

//optimized approach

int maxSubarraySum(vector<int> & arr, int n , int k){
    int i = 0;
    int j = 0;
    int sum = 0;
    int maxLen = 0;

    while(j < n){
        sum += arr[j];

        if(sum == k){
            maxLen = max(maxLen,j-i+1);
        }

        while(i <= j && sum > k){
            sum -= arr[i];
            i++;
        }
         if (sum == k) {
            maxLen = max(maxLen, j - i + 1);
        }
        j++;
    }
    return maxLen;
}

int main() {
    vector<int> arr = {2,3,5};
    int n=3,k=5;

    cout << maxSubarraySum(arr,n,k);
    return 0;
}