#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//brute force

// int maxScore(vector<int>& cardPoints, int k) {
//     int n = cardPoints.size();
//     int ans = 0;

//     for (int left = 0; left <= k; left++) {
//         int sum = 0;

//         for (int i = 0; i < left; i++) {
//             sum += cardPoints[i];
//         }

//         for (int i = n - (k - left); i < n; i++) {
//             sum += cardPoints[i];
//         }

//         ans = max(ans, sum);
//     }

//     return ans;
// }

//Two Pointer / Left + Right Sum

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();

    int lSum = 0;
    int rSum = 0;
    int maxSum = 0;

    for (int i = 0; i < k; i++) {
        lSum += cardPoints[i];
    }

    maxSum = lSum;

    int rIndex = n - 1;

    for (int i = k - 1; i >= 0; i--) {
        lSum -= cardPoints[i];

        rSum += cardPoints[rIndex];

        rIndex--;

        maxSum = max(maxSum, lSum + rSum);
    }

    return maxSum;
}


int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << maxScore(cardPoints, k) << endl;

    return 0;
}