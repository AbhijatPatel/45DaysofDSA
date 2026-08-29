#include <iostream>
#include <vector>
#include <stack>
using namespace std;

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {

            int index = i % n;

            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            if (i < n && !st.empty()) {
                ans[index] = st.top();
            }

            st.push(nums[index]);
        }

        return ans;
    }


int main() {
    vector<int> nums = {1, 2, 1};

    vector<int> ans = nextGreaterElements(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}