#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int priority(char c) {
    if (c == '^')
        return 3;

    if (c == '*' || c == '/')
        return 2;

    if (c == '+' || c == '-')
        return 1;

    return 0;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++) {

        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {

            ans += s[i];
        }

        else if (s[i] == '(') {
            st.push(s[i]);
        }

        else if (s[i] == ')') {

            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }

            st.pop();
        }

        else {

            while (!st.empty() &&
                   st.top() != '(' &&
                   priority(st.top()) > priority(s[i])) {

                ans += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    string s;

    cout << "Enter infix expression: ";
    cin >> s;

    cout << "Prefix expression: "
         << infixToPrefix(s) << endl;

    return 0;
}