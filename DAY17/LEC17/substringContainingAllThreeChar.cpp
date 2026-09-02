#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Brute Force Approach
// Time  : O(n²)
// Space : O(1)

// int numberOfSubstrings(string s) {
//     int n = s.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         int cnt[3] = {0, 0, 0};

//         for (int j = i; j < n; j++) {
//             cnt[s[j] - 'a']++;

//             if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
//                 ans += n - j;
//                 break;
//             }
//         }
//     }

//     return ans;
// }

//keep track of the last position
// Time  : O(n)
// Space : O(1)

int numberOfSubstrings(string s) {
    int last[3] = {-1, -1, -1};
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {

        last[s[i] - 'a'] = i;

        if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
            ans += min({last[0], last[1], last[2]}) + 1;
        }
    }

    return ans;
}

//Sliding Window 
// Time  : O(n)
// Space : O(1)

// int numberOfSubstrings(string s) {
//     int n = s.size();

//     int left = 0;
//     int ans = 0;

//     int cnt[3] = {0, 0, 0};

//     for (int right = 0; right < n; right++) {

//         cnt[s[right] - 'a']++;

//         while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {

//             ans += n - right;

//             cnt[s[left] - 'a']--;

//             left++;
//         }
//     }

//     return ans;
// }


int main() {
    string s = "abcabc";

    cout << numberOfSubstrings(s) << endl;

    return 0;
}