#include <bits/stdc++.h>
using namespace std;

void fun(int index, vector<int>& candidates, int target,
         vector<int>& ds, vector<vector<int>>& ans) {

    // Target reached
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    // Out of elements
    if (index == candidates.size()) {
        return;
    }

    // Take current element
    if (candidates[index] <= target) {

        ds.push_back(candidates[index]);

        // index stays same because
        // we can use the same element again
        fun(index, candidates, target - candidates[index],
            ds, ans);

        // Backtrack
        ds.pop_back();
    }

    // Not take current element
    fun(index + 1, candidates, target, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates,
                                   int target) {

    vector<vector<int>> ans;
    vector<int> ds;

    fun(0, candidates, target, ds, ans);

    return ans;
}

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> ans =
        combinationSum(candidates, target);

    cout << "\nCombinations:\n";

    for (auto &combination : ans) {

        cout << "[";

        for (int i = 0; i < combination.size(); i++) {

            cout << combination[i];

            if (i != combination.size() - 1)
                cout << ",";
        }

        cout << "]\n";
    }

    return 0;
}