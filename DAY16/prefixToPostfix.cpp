#include <iostream>
#include <stack>
using namespace std;

//Approach 1
// bool isOperand(char c) {
//     return (c >= 'a' && c <= 'z') ||
//            (c >= 'A' && c <= 'Z') ||
//            (c >= '0' && c <= '9');
// }

// string prefixToPostfix(string s) {
//     stack<string> st;

//     for (int i = s.size() - 1; i >= 0; i--) {

//         if (isOperand(s[i])) {
//             st.push(string(1, s[i]));
//         }
//         else {
//             string left = st.top();
//             st.pop();

//             string right = st.top();
//             st.pop();

//             string result = left + right + string(1, s[i]);

//             st.push(result);
//         }
//     }

//     return st.top();
// }

//Approach 2
string prefixToPostfix(const string& s) {
        // Your code goes here
        stack<string> st;

        for (int i = s.size()-1; i >= 0; i--) {

            if (isalnum(s[i])) {
                st.push(string(1, s[i]));
            }
            else {
                string left = st.top();
                st.pop();

                string right = st.top();
                st.pop();

                string result = left + right + string(1, s[i]);

                st.push(result);
            }
        }

        return st.top();
    }

int main() {
    string s;

    cout << "Enter prefix expression: ";
    cin >> s;

    cout << "Postfix expression: "
         << prefixToPostfix(s) << endl;

    return 0;
}