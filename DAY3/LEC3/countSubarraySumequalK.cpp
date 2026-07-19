#include <bits/stdc++.h>
using namespace std;

//Brute force
// int countSubarraySumk(vector<int> &arr, int k) {

//     int n = arr.size();
//     int cnt = 0;

//     for(int i = 0; i < n; i++) {

//         int sum = 0;

//         for(int j = i; j < n; j++) {

//             sum += arr[j];

//             if(sum == k)
//                 cnt++;
//         }
//     }

//     return cnt;
// }

//optimal approach
int countSubarraySumk(vector<int> &arr, int k) {

    unordered_map<int,int> mp;

    mp[0] = 1;

    int sum = 0;
    int cnt = 0;

    for(int i = 0; i < arr.size(); i++) {

        sum += arr[i];

        if(mp.find(sum - k) != mp.end())
            cnt += mp[sum - k];

        mp[sum]++;
    }

    return cnt;
}

int main() {

    vector<int> arr = {1,2,3};
    int k = 3;

    cout << countSubarraySumk(arr, k);

    return 0;
}