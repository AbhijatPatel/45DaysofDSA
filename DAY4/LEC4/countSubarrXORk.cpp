#include <bits/stdc++.h>
using namespace std;

//brute force

// int countSubarrXORk(vector<int> & arr,int n,int k){
//     int count = 0;

//     for(int i=0;i<n;i++){
//         int cal_XOR = 0;

//         for(int j=i;j<n;j++){
//             cal_XOR ^= arr[j];

//              if(cal_XOR == k)
//         count++;
//         }  
//     }
//     return count;
// }


// Time Complexity: O(n²)
// Space Complexity: O(1)

//better approach

int countSubarrXORk(vector<int> & arr,int n,int k){
    int count = 0;
    int curr_XOR = 0;

    map<int,int> mp;
    mp[0] = 1;

    for(int i=0;i<n;i++){
        curr_XOR ^= arr[i];

        if(curr_XOR == k)
        count++;

        else{
            if(mp.find(curr_XOR ^ k) != mp.end()){
                count += mp[curr_XOR ^ k];
            }
            
        }
        mp[curr_XOR]++;
    }
    return count;
}

// Time Complexity: O(n log n) with map
// Space Complexity: O(n)

int main() {
    vector<int> arr = {4,2,2,6,4};
    int k = 6;

    cout << countSubarrXORk(arr,arr.size(),k);
    return 0;
}