#include <bits/stdc++.h>
using namespace std;

//brute force
// Time  : O(n²)
// Space : O(n)

// int subarraysWithKDistinct(vector<int>& nums, int k) {
//     int n = nums.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {

//         unordered_map<int, int> mp;

//         for (int j = i; j < n; j++) {

//             mp[nums[j]]++;

//             if (mp.size() == k) {
//                 ans++;
//             }

//             if (mp.size() > k) {
//                 break;
//             }
//         }
//     }

//     return ans;
// }

//sliding window
// T.C = O(2N)
//S.C = o(N)
int atMost(vector<int>& nums, int k) {
    if (k == 0) {
        return 0;
    }

    int left = 0;
    int ans = 0;

    unordered_map<int, int> mp;

    for (int right = 0; right < nums.size(); right++) {

        mp[nums[right]]++;

        while (mp.size() > k) {

            mp[nums[left]]--;

            if (mp[nums[left]] == 0) {
                mp.erase(nums[left]);
            }

            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

int main() {

    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    cout << subarraysWithKDistinct(nums, k) << endl;

    return 0;
}