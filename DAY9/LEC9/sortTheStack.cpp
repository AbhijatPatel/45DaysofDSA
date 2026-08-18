#include <bits/stdc++.h>
using namespace std;

    void insertTopElm(int x, stack<int> &st) {
        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }

        int topElm = st.top();
        st.pop();

        insertTopElm(x, st);
        st.push(topElm);
    }

    void sortStack(stack<int> &st) {
        if (st.empty())
            return;

        int topElm = st.top();
        st.pop();

        sortStack(st);
        insertTopElm(topElm, st);
    }

int main() {
    stack<int> st;

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}