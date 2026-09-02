#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//brute
// Time  : O(n²)
// Space : O(k)

// int longestSubstring(string s, int k) {
//     int n = s.size();
//     int maxLen = 0;

//     for (int i = 0; i < n; i++) {
//         unordered_map<char, int> mp;

//         for (int j = i; j < n; j++) {
//             mp[s[j]]++;

//             if (mp.size() > k) {
//                 break;
//             }

//             maxLen = max(maxLen, j - i + 1);
//         }
//     }

//     return maxLen;
// }

//sliding window
// Time  : O(n) average
// Space : O(k)

int longestSubstring(string s, int k) {
    int left = 0;
    int maxLen = 0;

    unordered_map<char, int> mp;

    for (int right = 0; right < s.size(); right++) {
        mp[s[right]]++;

         //while  
         if(mp.size() > k) {
            mp[s[left]]--;

            if (mp[s[left]] == 0) {
                mp.erase(s[left]);
            }

            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

//sliding window with frequency
// Time  : O(n)
// Space : O(256)
//       = O(1)

// int longestSubstring(string s, int k) {
//     int freq[256] = {0};

//     int left = 0;
//     int distinct = 0;
//     int maxLen = 0;

//     for (int right = 0; right < s.size(); right++) {

//         if (freq[s[right]] == 0) {
//             distinct++;
//         }

//         freq[s[right]]++;

//         while (distinct > k) {

//             freq[s[left]]--;

//             if (freq[s[left]] == 0) {
//                 distinct--;
//             }

//             left++;
//         }

//         maxLen = max(maxLen, right - left + 1);
//     }

//     return maxLen;
// }



int main() {
    string s = "aabbcccd";
    int k = 2;

    cout << longestSubstring(s, k) << endl;

    return 0;
}