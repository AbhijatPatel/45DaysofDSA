#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//Stack approach

    // vector<int> asteroidCollision(vector<int>& asteroids) {

    //     stack<int> st;

    //     for (int i = 0; i < asteroids.size(); i++) {

    //         int current = asteroids[i];
    //         bool destroyed = false;

    //         while (!st.empty() && st.top() > 0 && current < 0) {

    //             if (abs(st.top()) < abs(current)) {
    //                 st.pop();
    //             }
    //             else if (abs(st.top()) == abs(current)) {
    //                 st.pop();
    //                 destroyed = true;
    //                 break;
    //             }
    //             else {
    //                 destroyed = true;
    //                 break;
    //             }
    //         }

    //         if (!destroyed) {
    //             st.push(current);
    //         }
    //     }

    //     vector<int> ans;

    //     while (!st.empty()) {
    //         ans.push_back(st.top());
    //         st.pop();
    //     }

    //     reverse(ans.begin(), ans.end());

    //     return ans;
    // }

    //vector as stack approach

    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            int current = asteroids[i];
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && current < 0) {

                if (st.back() < -current) {
                    st.pop_back();
                }
                else if (st.back() == -current) {
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(current);
            }
        }

        return st;
    }

int main() {

    vector<int> asteroids = {3, 5, -6, 2, -1, 4};

    vector<int> ans = asteroidCollision(asteroids);

    cout << "Final asteroids: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}