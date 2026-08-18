#include <bits/stdc++.h>
using namespace std;

    void fun(int index, vector<int>& ds, vector<int>& nums,
             int n, vector<vector<int>>& ans) {

        // Base case
        if (index == n) {
            ans.push_back(ds);
            return;
        }

        // Don't take nums[index]
        fun(index + 1, ds, nums, n, ans);

        // Take nums[index]
        ds.push_back(nums[index]);

        fun(index + 1, ds, nums, n, ans);

        // Backtrack
        ds.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        fun(0, ds, nums, nums.size(), ans);

        return ans;
    }

int main() {

 vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = subsets(nums);

    // Print all subsets
    cout << "All subsets are:\n";

    for (auto subset : ans) {

        cout << "[ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}