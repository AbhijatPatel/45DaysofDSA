#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//brute force

//  int largestRectangleArea(vector<int>& heights) {

//         int n = heights.size();
//         int maxArea = 0;

//         for (int i = 0; i < n; i++) {

//             int minHeight = heights[i];

//             for (int j = i; j < n; j++) {

//                 minHeight = min(minHeight, heights[j]);

//                 int width = j - i + 1;

//                 int area = minHeight * width;

//                 maxArea = max(maxArea, area);
//             }
//         }

//         return maxArea;
//     }

//previous smaller + next smaller

// int largestRectangleArea(vector<int>& heights) {

//         int n = heights.size();

//         vector<int> left(n);
//         vector<int> right(n);

//         stack<int> st;

//         // Previous Smaller Element
//         for (int i = 0; i < n; i++) {

//             while (!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }

//             if (st.empty()) {
//                 left[i] = -1;
//             }
//             else {
//                 left[i] = st.top();
//             }

//             st.push(i);
//         }

//         while (!st.empty()) {
//             st.pop();
//         }

//         // Next Smaller Element
//         for (int i = n - 1; i >= 0; i--) {

//             while (!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }

//             if (st.empty()) {
//                 right[i] = n;
//             }
//             else {
//                 right[i] = st.top();
//             }

//             st.push(i);
//         }

//         int maxArea = 0;

//         for (int i = 0; i < n; i++) {

//             int width = right[i] - left[i] - 1;

//             int area = heights[i] * width;

//             maxArea = max(maxArea, area);
//         }

//         return maxArea;
//     }


//one stack or one pass

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    stack<int> st;

    int maxArea = 0;

    for (int i = 0; i <= n; i++) {

        while (!st.empty() &&
               (i == n || heights[st.top()] > heights[i])) {

            int element = heights[st.top()];

            st.pop();

            int nsc = i;

            int psc;

            if (st.empty()) {
                psc = -1;
            }
            else {
                psc = st.top();
            }

            int width = nsc - psc - 1;

            int area = element * width;

            maxArea = max(maxArea, area);
        }

        if (i < n) {
            st.push(i);
        }
    }

    return maxArea;
}

int main() {

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int answer = largestRectangleArea(heights);

    cout << "Largest Rectangle Area = " << answer << endl;

    return 0;
}