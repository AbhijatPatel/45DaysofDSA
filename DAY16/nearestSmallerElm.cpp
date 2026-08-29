#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Approach - Nearest smaller to left.

// vector<int> nearestSmallerLeft(vector<int> arr) {
//     int n = arr.size();

//     vector<int> ans(n, -1);
//     stack<int> st;

//     for (int i = 0; i < n; i++) {

//         while (!st.empty() && st.top() >= arr[i]) {
//             st.pop();
//         }

//         if (!st.empty()) {
//             ans[i] = st.top();
//         }

//         st.push(arr[i]);
//     }

//     return ans;
// }

//Approach - Nearest smaller to right.

vector<int> nearestSmallerRight(vector<int> arr) {
    int n = arr.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}


int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> ans = nearestSmallerRight(arr);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}