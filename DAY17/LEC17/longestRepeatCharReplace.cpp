#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//brute force
// Time  : O(26 × n²) = O(n²)
// Space : O(26) = O(1)
// int characterReplacement(string s, int k) {
//     int n = s.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         int freq[26] = {0};
//         int maxFreq = 0;

//         for (int j = i; j < n; j++) {
//             freq[s[j] - 'A']++;

//             maxFreq = max(maxFreq, freq[s[j] - 'A']);

//             int len = j - i + 1;
//             int changes = len - maxFreq;

//             if (changes <= k) {
//                 ans = max(ans, len);
//             }
//         }
//     }

//     return ans;
// }

//sliding window - while
// Time  : O(26 × n)
//       = O(n)

// Space : O(26)
//       = O(1)

int characterReplacement(string s, int k) {
    int left = 0;
    int ans = 0;

    int freq[26] = {0};

    for (int right = 0; right < s.size(); right++) {

        freq[s[right] - 'A']++;

        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        //while anf for optimize use if
        if ((right - left + 1) - maxFreq > k) {

            freq[s[left] - 'A']--;

            left++;

            maxFreq = 0;

            for (int i = 0; i < 26; i++) {
                maxFreq = max(maxFreq, freq[i]);
            }
        }
        if((right-left+1)-maxFreq <= k){
              ans = max(ans, right - left + 1);
        }
    }

    return ans;
}


int main() {
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k) << endl;

    return 0;
}