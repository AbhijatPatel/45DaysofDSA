#include <bits/stdc++.h>
using namespace std;

// Function to generate all unique subsets
void fun(int index,
         vector<int>& nums,
         vector<int>& ds,
         vector<vector<int>>& ans)
{
    // Every time we enter this function,
    // the current ds is one valid subset.
    // So, add it to the answer.
    ans.push_back(ds);

    // Try choosing every element from index onwards
    for (int i = index; i < nums.size(); i++)
    {
        // If the current element is the same as the previous element
        // at the SAME LEVEL, skip it.
        //
        // This prevents duplicate subsets.
        //
        // Example:
        // nums = [1, 2, 2]
        //
        // When i moves from first 2 to second 2 at the same level,
        // we skip the second 2.
        if (i > index && nums[i] == nums[i - 1])
        {
            continue;
        }

        // Choose the current element
        ds.push_back(nums[i]);

        // Recursively generate subsets
        // Start from i + 1 because we cannot choose
        // the same array element again.
        fun(i + 1, nums, ds, ans);

        // Backtracking:
        // Remove the last element so that we can try
        // another possibility.
        ds.pop_back();
    }
}


// Main function
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    // Sort the array first.
    //
    // This is important because duplicate elements
    // must be next to each other.
    //
    // Example:
    // [2, 1, 2]
    // becomes
    // [1, 2, 2]
    sort(nums.begin(), nums.end());

    // This will store all unique subsets
    vector<vector<int>> ans;

    // Temporary vector used to build each subset
    vector<int> ds;

    // Start recursion from index 0
    fun(0, nums, ds, ans);

    // Return all unique subsets
    return ans;
}


// Main function for VS Code
int main()
{
    // Input array
    vector<int> nums = {1, 2, 2};

    // Call the function
    vector<vector<int>> result = subsetsWithDup(nums);

    // Print all subsets
    cout << "All Unique Subsets:" << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}