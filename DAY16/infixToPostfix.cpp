#include <iostream>
#include <stack>
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

string infixToPostfix(string s) {
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
                   priority(st.top()) >= priority(s[i])) {

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

    return ans;
}

int main() {

    string s;

    cout << "Enter infix expression: ";
    cin >> s;

    cout << "Postfix expression: "
         << infixToPostfix(s) << endl;

    return 0;
}