#include <bits/stdc++.h>
using namespace std;

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {

            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void fun(int index, string &s, vector<string> &ds,
             vector<vector<string>> &ans) {

        // Base case
        if (index == s.size()) {
            ans.push_back(ds);
            return;
        }

        // Try every possible partition
        for (int i = index; i < s.size(); i++) {

            // Check if current substring is palindrome
            if (isPalindrome(s, index, i)) {

                // Take substring
                ds.push_back(s.substr(index, i - index + 1));

                // Recursion for remaining string
                fun(i + 1, s, ds, ans);

                // Backtrack
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> ds;

        fun(0, s, ds, ans);

        return ans;
    }

int main() {

    string s = "aab";

    vector<vector<string>> ans = partition(s);

    // Print answer
    for (auto &partition : ans) {

        cout << "[ ";

        for (auto &str : partition) {
            cout << str << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}