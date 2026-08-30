#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Brute force approach

//   long long sumSubArrayRanges(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = 0;

//         for (int i = 0; i < n; i++) {
//             int minimum = nums[i];
//             int maximum = nums[i];

//             for (int j = i; j < n; j++) {
//                 minimum = min(minimum, nums[j]);
//                 maximum = max(maximum, nums[j]);

//                 ans += maximum - minimum;
//             }
//         }

//         return ans;
//     }

//Two  array + monotonic stack approach

long long sumSubArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);

        long long minSum = 0;
        long long maxSum = 0;

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            // left[i] = st.empty() ? -1 : st.top();
            if (st.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            minSum += 1LL * nums[i] * leftCount * rightCount;
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            // left[i] = st.empty() ? -1 : st.top();
             if (st.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            // right[i] = st.empty() ? n : st.top();
             if (st.empty()) {
                right[i] = n;
            }
            else {
                right[i] = st.top();
            }
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            maxSum += 1LL * nums[i] * leftCount * rightCount;
        }

        return maxSum - minSum;
    }


int main() {
    vector<int> nums = {1, 2, 3};

    long long ans = sumSubArrayRanges(nums);

    cout << "Sum of Subarray Ranges: " << ans << endl;

    return 0;
}