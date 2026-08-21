#include <bits/stdc++.h>
using namespace std;


    void fun(int index, vector<int>& candidates, int target,
             vector<int>& ds, vector<vector<int>>& ans) {

        // Target reached
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Try every possible element
        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate elements at the same level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no further element can work
            if (candidates[i] > target)
                break;

            // Choose
            ds.push_back(candidates[i]);

            // Move to i + 1 because each element can be used only once
            fun(i + 1, candidates,
                target - candidates[i],
                ds, ans);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        // Sort is required for:
        // 1. Duplicate handling
        // 2. Early stopping
        sort(candidates.begin(), candidates.end());

        fun(0, candidates, target, ds, ans);

        return ans;
    }
int main() {

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result =
        combinationSum2(candidates, target);

    cout << "Combinations are:\n";

    for (auto &combination : result) {
        cout << "[ ";

        for (int x : combination) {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}