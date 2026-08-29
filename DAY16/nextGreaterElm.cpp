#include <iostream>
#include <vector>
#include<stack>
using namespace std;

//Approach - Brute force 

// vector<int> nextGreater(vector<int> arr) {
//     int n = arr.size();
//     vector<int> ans(n, -1);

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] > arr[i]) {
//                 ans[i] = arr[j];
//                 break;
//             }
//         }
//     }

//     return ans;
// }

// Approach - Optimized(Monotonic Stack use).


vector<int> nextGreater(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && st.top() <= arr[i]) {
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

    vector<int> ans = nextGreater(arr);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}