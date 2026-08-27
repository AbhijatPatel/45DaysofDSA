#include <iostream>
#include <stack>
using namespace std;

    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (st.empty())
                    return false;

                char ch = st.top();
                st.pop();

                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == ']' && ch != '[') ||
                    (s[i] == '}' && ch != '{')) {
                    return false;
                }
            }
        }

        return st.empty();
    }

int main() {

    string s;

    cout << "Enter brackets: ";
    cin >> s;

    if (isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}