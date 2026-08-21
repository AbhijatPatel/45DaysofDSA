#include <bits/stdc++.h>
using namespace std;

    void fun(int index, vector<int>& nums, int n,
             int sum, vector<int>& ans) {

        // Base case
        if (index == n) {
            ans.push_back(sum);
            return;
        }

        // Take the current element
        fun(index + 1, nums, n,
            sum + nums[index], ans);

        // Do not take the current element
        fun(index + 1, nums, n,
            sum, ans);
    }

    vector<int> subsetSums(vector<int>& nums) {

        vector<int> ans;

        fun(0, nums, nums.size(), 0, ans);

        return ans;
    }

int main() {


    vector<int> nums = {1, 2, 3};

    vector<int> result = subsetSums(nums);

    cout << "Subset Sums: ";

    for (int sum : result) {
        cout << sum << " ";
    }

    cout << endl;

    return 0;
}