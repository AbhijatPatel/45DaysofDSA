#include <iostream>
#include <stack>
using namespace std;

//Approach 1
// bool isOperand(char c) {
//     return (c >= 'a' && c <= 'z') ||
//            (c >= 'A' && c <= 'Z') ||
//            (c >= '0' && c <= '9');
// }

// string postfixToPrefix(string s) {
//     stack<string> st;

//     for (int i = 0; i < s.size(); i++) {

//         if (isOperand(s[i])) {
//             st.push(string(1, s[i]));
//         }
//         else {
//             string right = st.top();
//             st.pop();

//             string left = st.top();
//             st.pop();

//             string result = s[i] + left + right;

//             st.push(result);
//         }
//     }

//     return st.top();
// }

//Approach 2
    string postfixToPrefix(string postfix) {
        stack<string> st;

        for (int i = 0; i < postfix.size(); i++) {

            if (isalnum(postfix[i])) {
                st.push(string(1, postfix[i]));
            }
            else {
                string right = st.top();
                st.pop();

                string left = st.top();
                st.pop();

                string result = string(1, postfix[i]) + left + right;

                st.push(result);
            }
        }

        return st.top();
    }

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Prefix expression: "
         << postfixToPrefix(postfix) << endl;

    return 0;
}