#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

string prefixToInfix(string s) {
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; i--) {

        if (isOperand(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            string left = st.top();
            st.pop();

            string right = st.top();
            st.pop();

            string temp = "(" + left + s[i] + right + ")";

            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    string s;

    cout << "Enter prefix expression: ";
    cin >> s;

    cout << "Infix expression: "
         << prefixToInfix(s) << endl;

    return 0;
}