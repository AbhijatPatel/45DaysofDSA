#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//brute force

// int longestOnes(vector<int>& nums, int k) {
//     int n = nums.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         int zeros = 0;

//         for (int j = i; j < n; j++) {
//             if (nums[j] == 0) {
//                 zeros++;
//             }

//             if (zeros > k) {
//                 break;
//             }

//             ans = max(ans, j - i + 1);
//         }
//     }

//     return ans;
// }

//sliding window

// int longestOnes(vector<int>& nums, int k) {
//     int left = 0;
//     int zeros = 0;
//     int ans = 0;

//     for (int right = 0; right < nums.size(); right++) {

//         if (nums[right] == 0) {
//             zeros++;
//         }

//         while (zeros > k) {
//             if (nums[left] == 0) {
//                 zeros--;
//             }

//             left++;
//         }

//         ans = max(ans, right - left + 1);
//     }

//     return ans;
// }

//Sliding Window Using k Directly

int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++) {

        if (nums[right] == 0) {
            k--;
        }

        while (k < 0) {

            if (nums[left] == 0) {
                k++;
            }

            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}



int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << longestOnes(nums, k) << endl;

    return 0;
}