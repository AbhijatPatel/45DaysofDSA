#include <bits/stdc++.h>
using namespace std;

    void fun(int i, int n, vector<string>& ans, string& s) {

        // Base case
        if (i >= n) {
            ans.push_back(s);
            return;
        }

        // Put 0
        s[i] = '0';
        fun(i + 1, n, ans, s);

        // Put 1
        s[i] = '1';
        fun(i + 2, n, ans, s);

        // Backtrack
        s[i] = '0';
    }

    vector<string> generateBinaryStrings(int n) {

        vector<string> ans;
        string s(n, '0');

        fun(0, n, ans, s);

        return ans;
    }

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> ans = generateBinaryStrings(n);

    cout << "Binary strings without consecutive 1s:\n";

    for (string str : ans) {
        cout << str << endl;
    }

    return 0;
}