#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//Approach - when two array is given
vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2) {
    int n = nums2.size();

    stack<int> st;
    unordered_map<int, int> mp;

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        if (!st.empty()) {
            mp[nums2[i]] = st.top();
        }
        else {
            mp[nums2[i]] = -1;
        }

        st.push(nums2[i]);
    }

    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++) {
        ans.push_back(mp[nums1[i]]);
    }

    return ans;
}
//Time Complexity: O(nums1.size() + nums2.size())
//Space Complexity: O(nums2.size())

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}