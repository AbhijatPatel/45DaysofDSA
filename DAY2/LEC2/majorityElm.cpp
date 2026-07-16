#include <bits/stdc++.h>
using namespace std;

//brute force approach
// int majorityElement(vector<int>& arr, int n) {

//     for (int i = 0; i < n; i++) {
//         int count = 0;

//         for (int j = 0; j < n; j++) {
//             if (arr[i] == arr[j])
//                 count++;
//         }

//         if (count > n / 2)
//             return arr[i];
//     }

//     return -1;
// }

//better approach

// int majorityElement(vector<int>& arr,int n) {

//     unordered_map<int,int> mp;

//     for (int i=0;i<n;i++) {
//         mp[arr[i]]++;
//     }

//     for (auto it : mp) {
//         if (it.second > n / 2)
//             return it.first;
//     }

//     return -1;
// }

// optimized approach
int majorityElement(vector<int>& arr,int n){
    int  count = 0;//count current votes count 
    int elm;//store current candidate for the majority element

    for(int i=0;i<arr.size();i++){
     if(count == 0){
        count = 1;
        elm = arr[i];
     }

     else if(elm == arr[i]){
        count++;
     }
     else {
        count--;
     }
    }
    return elm;
}

int main() { 
    vector<int> arr = {2,2,1,1,1,2,2};

    cout << majorityElement(arr,arr.size());
     return 0;
}