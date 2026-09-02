#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//brute force
//Time  = O(n²)
//Space = O(1)

// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     int n = nums.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         int sum = 0;

//         for (int j = i; j < n; j++) {
//             sum += nums[j];

//             if (sum == goal) {
//                 ans++;
//             }

//             if (sum > goal) {
//                 break;
//             }
//         }
//     }

//     return ans;
// }

//Prefix Sum + HashMap
// Time  = O(n) average
// Space = O(n)

// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     unordered_map<int, int> mp;

//     mp[0] = 1;

//     int sum = 0;
//     int ans = 0;

//     for (int num : nums) {
//         sum += num;

//         if (mp.find(sum - goal) != mp.end()) {
//             ans += mp[sum - goal];
//         }

//         mp[sum]++;
//     }

//     return ans;
// }

//sliding window
//Time  = O(n)
// Space = O(1)

int atMost(vector<int>& nums, int goal) {
    if (goal < 0) {
        return 0;
    }

    int left = 0;
    int sum = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++) {

        sum += nums[right];

        while (sum > goal) {
            sum -= nums[left];
            left++;
        }

        ans += right - left + 1;
    }

    return ans;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}




int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << numSubarraysWithSum(nums, goal) << endl;

    return 0;
}