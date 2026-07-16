#include <bits/stdc++.h>
using namespace std;

//brute force approach
// pair<int,int> twoSum(vector<int> & arr, int target){
//     int n = arr.size();

//    for(int i = 0; i < n; i++){
//         for(int j = i+1; j < n; j++){
//             if(arr[i] + arr[j] == target)
//             return{i,j};
//         }
//     }
//     return{-1,-1};
// }

//better approach
// pair<int,int> twoSum(vector<int> & arr, int target){
//     unordered_map<int,int> mp;
//     for(int i = 0; i < arr.size(); i++){
//         mp[arr[i]] = i;
//     }

//     for(int i = 0; i < arr.size(); i++){
//         int rem = target - arr[i];
//         if(mp.find(rem) != mp.end()){
//             return{i,mp[rem]};
//         }
//     }
//     return {-1,-1};
// }



//two pointer approach

pair<int, int> twoSum(vector<int> &arr, int target) {
    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {
        int sum = arr[i] + arr[j];

        if (sum == target) {
            return {i, j};
        }
        else if (sum < target) {
            i++;        
        }
        else {
            j--;       
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {2,6,5,8,11};
    int target = 14;

    pair<int,int> ans = twoSum(arr,target);
    cout << ans.first << " " << ans.second << " ";
    return 0;
}