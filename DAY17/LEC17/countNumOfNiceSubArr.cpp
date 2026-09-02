#include <bits/stdc++.h>
using namespace std;

//brute force
// Time  : O(n²)
// Space : O(1)

// int numberOfNiceSubarrays(vector<int>& nums, int k) {
//     int n = nums.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         int odd = 0;

//         for (int j = i; j < n; j++) {

//             if (nums[j] % 2 == 1) {
//                 odd++;
//             }

//             if (odd == k) {
//                 ans++;
//             }

//             if (odd > k) {
//                 break;
//             }
//         }
//     }

//     return ans;
// }

//Prefix Sum + HashMap
// Time  : O(n) average
// Space : O(n)


// int numberOfNiceSubarrays(vector<int>& nums, int k) {
//     unordered_map<int, int> mp;

//     mp[0] = 1;

//     int sum = 0;
//     int ans = 0;

//     for (int num : nums) {

//         sum += num % 2;

//         if (mp.find(sum - k) != mp.end()) {
//             ans += mp[sum - k];
//         }

//         mp[sum]++;
//     }

//     return ans;
// }

//sliding Window
// Time  : O(n)
// Space : O(1)

int atMost(vector<int>& nums, int goal) {
    if (goal < 0) {
        return 0;
    }

    int left = 0;
    int sum = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++) {

        sum += nums[right] % 2;

        while (sum > goal) {
            sum -= nums[left] % 2;
            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

int numberOfNiceSubarrays(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << numberOfNiceSubarrays(nums, k) << endl;

    return 0;
}