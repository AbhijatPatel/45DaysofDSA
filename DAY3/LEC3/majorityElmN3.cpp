#include <bits/stdc++.h>
using namespace std;

//brute force
// int majorityElmN3(vector<int> & arr, int n){

//     for(int i=0;i<n;i++){
//         int count=0;

//         for(int j=0;j<n;j++){
//             if(arr[i]==arr[j]){
//                 count++;
//             }
//         }
//         if(count>(n/3)){
//             return arr[i];
//         }
//     }
//     return -1;
// }
//T.C = O(n^2)

//optimized approach

int majorityElmN3(vector<int> & arr, int n){

    map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto it :mp){
        if(it.second > (n/3)){
            return it.first;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,2,2,3,2};

    cout << majorityElmN3(arr,arr.size());
    return 0;
}