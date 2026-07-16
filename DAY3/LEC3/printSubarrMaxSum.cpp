#include <bits/stdc++.h>
using namespace std;

void printMaxSubarraySum(vector<int> &arr, int n) {

    int sum = 0;
    int maxSum = INT_MIN;

    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;

    for (int i = 0; i < n; i++) {

        if (sum == 0) {
            start = i;
        }

        sum += arr[i];

        if (sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum Sum = " << maxSum << endl;

    cout << "Subarray : ";

    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    printMaxSubarraySum(arr, arr.size());

    return 0;
}