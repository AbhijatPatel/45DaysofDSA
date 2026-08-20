#include <bits/stdc++.h>
using namespace std;

int fun(int index, vector<int>& nums, int n, int sum, int k) {

    // Base case5
    if (index == n) {
        if (sum == k)
            return 1;

        return 0;
    }

    // This works when all array elements are non-negative
    if (sum > k)
        return 0;

    // Take current element
    int take = fun(
        index + 1,
        nums,
        n,
        sum + nums[index],
        k
    );

    // Do not take current element
    int notTake = fun(
        index + 1,
        nums,
        n,
        sum,
        k
    );

    return take + notTake;
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
    return fun(0, nums, nums.size(), 0, k);
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;

    cout << "Enter target sum: ";
    cin >> k;

    int ans = countSubsequenceWithTargetSum(nums, k);

    cout << "Number of subsequences with target sum: "
         << ans << endl;

    return 0;
}