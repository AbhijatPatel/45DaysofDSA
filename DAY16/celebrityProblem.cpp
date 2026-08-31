#include <iostream>
#include <vector>
#include<stack>
using namespace std;

//stack approach

    // int celebrity(vector<vector<int>>& M, int n) {

    //     stack<int> st;

    //     for (int i = 0; i < n; i++) {
    //         st.push(i);
    //     }

    //     while (st.size() > 1) {

    //         int A = st.top();
    //         st.pop();

    //         int B = st.top();
    //         st.pop();

    //         if (M[A][B] == 1) {
    //             st.push(B);
    //         }
    //         else {
    //             st.push(A);
    //         }
    //     }

    //     int candidate = st.top();

    //     for (int i = 0; i < n; i++) {

    //         if (i != candidate) {

    //             if (M[candidate][i] == 1) {
    //                 return -1;
    //             }

    //             if (M[i][candidate] == 0) {
    //                 return -1;
    //             }
    //         }
    //     }

    //     return candidate;
    // }

    //two pointer approach

     int celebrity(vector<vector<int>>& M, int n) {

        int candidate = 0;

        for (int i = 1; i < n; i++) {

            if (M[candidate][i] == 1) {
                candidate = i;
            }
        }

        for (int i = 0; i < n; i++) {

            if (i != candidate) {

                if (M[candidate][i] == 1) {
                    return -1;
                }

                if (M[i][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }

int main() {

    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();

    int result = celebrity(M, n);

    if (result == -1) {
        cout << "No celebrity found" << endl;
    }
    else {
        cout << "Celebrity is person: " << result << endl;
    }

    return 0;
}
