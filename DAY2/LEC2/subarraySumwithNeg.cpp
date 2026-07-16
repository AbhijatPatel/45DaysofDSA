#include <bits/stdc++.h>
using namespace std;

int subarraySumKwithneg(vector<int> & arr,int n,int k){
    int maxLen = 0;
    int prefixSum = 0;

    map<int,int> mp;

    for(int i = 0; i < n; i++){
        prefixSum += arr[i];

        if(mp.find(prefixSum) == mp.end()){
        mp[prefixSum] = i;
}

        if(prefixSum == k){
            maxLen = max(maxLen,i+1);
        }

        else if(mp.find(prefixSum-k) != mp.end()){
            int t = mp[prefixSum-k];
            maxLen = max(maxLen, i-t);
        }
    }
    return maxLen;
 }


int main() {
    vector<int> arr = {3,0,0,0,6};
    int n = 5, k = 6;

    cout << subarraySumKwithneg(arr,n,k);
    return 0;
}