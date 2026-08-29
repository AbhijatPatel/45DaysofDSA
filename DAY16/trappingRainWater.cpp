#include <iostream>
#include <vector>
#include<stack>
using namespace std;

// Approach - brute force

// int trap(vector<int> height) {
//     int n = height.size();
//     int water = 0;

//     for (int i = 0; i < n; i++) {

//         int leftMax = 0;
//         int rightMax = 0;

//         for (int j = 0; j <= i; j++) {
//             leftMax = max(leftMax, height[j]);
//         }

//         for (int j = i; j < n; j++) {
//             rightMax = max(rightMax, height[j]);
//         }

//         water += min(leftMax, rightMax) - height[i];
//     }

//     return water;
// }
// Time  = O(n²)
// Space = O(1)

// Approach - prefix & suffix Maximum

// int trap(vector<int> height) {
//     int n = height.size();

//     vector<int> leftMax(n);
//     vector<int> rightMax(n);

//     leftMax[0] = height[0];

//     for (int i = 1; i < n; i++) {
//         leftMax[i] = max(leftMax[i - 1], height[i]);
//     }

//     rightMax[n - 1] = height[n - 1];

//     for (int i = n - 2; i >= 0; i--) {
//         rightMax[i] = max(rightMax[i + 1], height[i]);
//     }

//     int water = 0;

//     for (int i = 0; i < n; i++) {
//         water += min(leftMax[i], rightMax[i]) - height[i];
//     }

//     return water;
// }

// Time  = O(n)
// Space = O(n)

// Approach - two pointer

// int trap(vector<int> height) {
//     int left = 0;
//     int right = height.size() - 1;

//     int leftMax = 0;
//     int rightMax = 0;

//     int water = 0;

//     while (left <= right) {

//         if (height[left] <= height[right]) {

//             if (height[left] >= leftMax) {
//                 leftMax = height[left];
//             }
//             else {
//                 water += leftMax - height[left];
//             }

//             left++;
//         }
//         else {

//             if (height[right] >= rightMax) {
//                 rightMax = height[right];
//             }
//             else {
//                 water += rightMax - height[right];
//             }

//             right--;
//         }
//     }

//     return water;
// }

// Time  = O(n)
// Space = O(1)

// Approach - monotonic stack


int trap(vector<int> height) {
    int n = height.size();

    stack<int> st;
    int water = 0;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && height[i] > height[st.top()]) {

            int bottom = st.top();
            st.pop();

            if (st.empty()) {
                break;
            }

            int left = st.top();

            int width = i - left - 1;

            int h = min(height[left], height[i]) - height[bottom];

            water += width * h;
        }

        st.push(i);
    }

    return water;
}

// Time  = O(n)
// Space = O(n)

int main() {
    vector<int> height = {4, 2, 0, 3, 2, 5};

    cout << trap(height);

    return 0;
}