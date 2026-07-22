#include <bits/stdc++.h>
using namespace std;

//brute force
// int subArrSumZero(vector<int> & arr, int n){
//     int maxLen=0;

//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum +=arr[j];
//             if(sum == 0){
//                 maxLen =max(maxLen,j-i+1);
//             }
//         }
//     }
//     return maxLen;
// }

//better approach

int subArrSumZero(vector<int> & arr, int n){
    int maxLen = 0;
    int sum = 0;

    map<int,int> mp;

    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum == 0){
            maxLen = max(maxLen,i+1);
        }

        else if(mp.find(sum)!=mp.end()){
            maxLen = max(maxLen,i-mp[sum]);
        }
        else{
            mp[sum]=i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> arr = {9,-3,3,-1,6,-5};

    cout << subArrSumZero(arr,arr.size());
    return 0;
}