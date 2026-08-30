#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//brute force approach

// int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         long long ans = 0;
//         long long MOD = 1000000007;

//         for (int i = 0; i < n; i++) {

//             int minimum = arr[i];

//             for (int j = i; j < n; j++) {

//                 minimum = min(minimum, arr[j]);

//                 ans = (ans + minimum) % MOD;
//             }
//         }

//         return ans;
//     }

//two array + stack better approach

    // int sumSubarrayMins(vector<int>& arr) {

    //     int n = arr.size();
    //     long long MOD = 1000000007;

    //     vector<int> left(n);
    //     vector<int> right(n);

    //     stack<int> st;

    //     // Previous Smaller Element
    //     for (int i = 0; i < n; i++) {

    //         while (!st.empty() && arr[st.top()] > arr[i]) {
    //             st.pop();
    //         }

    //         if (st.empty()) {
    //             left[i] = -1;
    //         }
    //         else {
    //             left[i] = st.top();
    //         }

    //         st.push(i);
    //     }

    //     while (!st.empty()) {
    //         st.pop();
    //     }

    //     // Next Smaller or Equal Element
    //     for (int i = n - 1; i >= 0; i--) {

    //         while (!st.empty() && arr[st.top()] >= arr[i]) {
    //             st.pop();
    //         }

    //         if (st.empty()) {
    //             right[i] = n;
    //         }
    //         else {
    //             right[i] = st.top();
    //         }

    //         st.push(i);
    //     }

    //     long long ans = 0;

    //     for (int i = 0; i < n; i++) {

    //         long long leftCount = i - left[i];

    //         long long rightCount = right[i] - i;

    //         long long contribution =
    //             1LL * arr[i] * leftCount * rightCount;

    //         ans = (ans + contribution) % MOD;
    //     }

    //     return ans;
    // }

    //One pass Monotonic stack

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        long long MOD = 1000000007;

        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || arr[st.top()] > arr[i])) {

                int mid = st.top();
                st.pop();

                int left;

                if (st.empty()) {
                    left = -1;
                }
                else {
                    left = st.top();
                }

                int right = i;

                long long leftCount = mid - left;
                long long rightCount = right - mid;

                long long contribution =
                    1LL * arr[mid] * leftCount * rightCount;

                ans = (ans + contribution) % MOD;
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }




int main() {

    vector<int> arr = {3, 1, 2, 4};

    cout << "Answer: "
         << sumSubarrayMins(arr) << endl;

    return 0;
}