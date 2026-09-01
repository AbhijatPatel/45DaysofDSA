#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

//Brute force

// int lengthOfLongestSubstring(string s) {
//     int n = s.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         unordered_set<char> st;

//         for (int j = i; j < n; j++) {
//             if (st.count(s[j])) {
//                 break;
//             }

//             st.insert(s[j]);
//             ans = max(ans, j - i + 1);
//         }
//     }

//     return ans;
// }

//sliding window


// int lengthOfLongestSubstring(string s) {
//     unordered_set<char> st;

//     int left = 0;
//     int ans = 0;

//     for (int right = 0; right < s.size(); right++) {

//         while (st.count(s[right])) {
//             st.erase(s[left]);
//             left++;
//         }

//         st.insert(s[right]);

//         ans = max(ans, right - left + 1);
//     }

//     return ans;
// }

//Sliding Window + Frequency Array

// int lengthOfLongestSubstring(string s) {
//     int freq[256] = {0};

//     int left = 0;
//     int ans = 0;

//     for (int right = 0; right < s.size(); right++) {

//         freq[s[right]]++;

//         while (freq[s[right]] > 1) {
//             freq[s[left]]--;
//             left++;
//         }

//         ans = max(ans, right - left + 1);
//     }

//     return ans;
// }

int lengthOfLongestSubstring(string s) {
    int hash[256] ;
fill(hash, hash + 256, -1);

    int l = 0;
    int r = 0;
    int maxLen = 0;

    int n = s.size();

    while (r < n) {

        if (hash[s[r]] != -1) {
            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
        }

        int len = r - l + 1;

        maxLen = max(maxLen, len);

        hash[s[r]] = r;

        r++;
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}