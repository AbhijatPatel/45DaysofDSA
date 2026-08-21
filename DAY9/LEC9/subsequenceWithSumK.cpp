#include <iostream>
#include <vector>
using namespace std;

bool solve(int index, vector<int>& nums, int k) {

    // Target becomes 0 → subsequence found
    if (k == 0)
        return true;

    // Reached the end of the array
    if (index == nums.size())
        return false;

    // For non-negative array elements
    if (k < 0)
        return false;

    // Take nums[index]
    if (solve(index + 1, nums, k - nums[index]))
        return true;

    // Don't take nums[index]
    if (solve(index + 1, nums, k))
        return true;

    return false;
}

int main() {

    vector<int> nums = {1, 10, 4, 5};
    int k = 3;

    bool ans = solve(0, nums, k);

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}