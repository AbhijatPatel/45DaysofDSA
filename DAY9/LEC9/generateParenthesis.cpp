#include <bits/stdc++.h>
using namespace std;

// void solve(int n, int open,int close,string &s,
// vector<string> &ans){
//     if(s.size() == 2 * n){
//         ans.push_back(s);
//         return;
//     }
//     if(open < n){
//         s.push_back('(');
//         solve(n,open+1,close,s,ans);
//         s.pop_back();
//     }
//     if(close < open){
//         s.push_back(')');
//         solve(n,open,close+1,s,ans);
//         s.pop_back();
//     }
// }
//     vector<string> generateParenthesis(int n) {
//         vector<string>ans;
//         string s;
//         s.reserve(2 * n);
//         solve(n,0,0,s,ans);
//         return ans;
//     }


    void fun(int open, int close, string s, vector<string>& ans) {

        // Base case
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        // Place '('
        if (open > 0) {
            fun(open - 1, close, s + '(', ans);
        }

        // Place ')' only when a '(' is already placed
        if (close > open) {
            fun(open, close - 1, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        fun(n, n, "", ans);

        return ans;
    }

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> ans = generateParenthesis(n);

    cout << "Valid Parentheses:\n";

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}