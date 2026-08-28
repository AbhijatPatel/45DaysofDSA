#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

string postfixToInfix(string s) {
    stack<string> st;

    for (int i = 0; i < s.size(); i++) {

        if (isOperand(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            string right = st.top();
            st.pop();

            string left = st.top();
            st.pop();

            string result = "(" + left + s[i] + right + ")";

            st.push(result);
        }
    }

    return st.top();
}

int main() {

    string s;

    cout << "Enter postfix expression: ";
    cin >> s;

    cout << "Infix expression: "
         << postfixToInfix(s) << endl;

    return 0;
}