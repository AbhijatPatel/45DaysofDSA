#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fun(int ind, string digits, vector<string>& ans,
         string s, vector<string>& mp) {

    // Base case
    if (ind == digits.size()) {
        ans.push_back(s);
        return;
    }

    // Get letters for current digit
    int i = digits[ind] - '0';
    string letters = mp[i];

    // Try every letter
    for (char c : letters) {

        s.push_back(c);

        fun(ind + 1, digits, ans, s, mp);

        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {

    vector<string> ans;

    if (digits.empty()) {
        return ans;
    }

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    fun(0, digits, ans, "", mp);

    return ans;
}

int main() {

    string digits;

    cout << "Enter digits: ";
    cin >> digits;

    vector<string> ans = letterCombinations(digits);

    cout << "\nLetter Combinations:\n";

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}