#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//brute force

// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;

//         int n = nums.size();

//         for (int i = 0; i <= n - k; i++) {
//             int maximum = nums[i];

//             for (int j = i; j < i + k; j++) {
//                 maximum = max(maximum, nums[j]);
//             }

//             ans.push_back(maximum);
//         }

//         return ans;
//     }

//monotonic deque

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {

            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }


int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    cout << "Maximum of each sliding window: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

