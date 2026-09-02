#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

//brute force

// int totalFruit(vector<int>& fruits) {
//     int n = fruits.size();
//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         unordered_map<int, int> mp;

//         for (int j = i; j < n; j++) {
//             mp[fruits[j]]++;

//             if (mp.size() > 2)
//                 break;

//             ans = max(ans, j - i + 1);
//         }
//     }

//     return ans;
// }

// Time  = O(n²)
// Space = O(1)

//sliding window + map

// int totalFruit(vector<int>& fruits) {
//     int left = 0;
//     int right = 0;
//     int maxLen = 0;
//     int k = 2;

//     map<int, int> mp;

//     while (right < fruits.size()) {
//         mp[fruits[right]]++;

//         while (mp.size() > k) {
//             mp[fruits[left]]--;

//             if (mp[fruits[left]] == 0) {
//                 mp.erase(fruits[left]);
//             }

//             left++;
//         }

//         maxLen = max(maxLen, right - left + 1);

//         right++;
//     }

//     return maxLen;
// }

// Time  = O(n log 2) ≈ O(n)
// Space = O(1)

//sliding window+ unordered map


// int totalFruit(vector<int>& fruits) {
//     int left = 0, right = 0;
//     int maxLen = 0;

//     unordered_map<int, int> mp;

//     for (int right = 0; right < fruits.size(); right++) {
//         mp[fruits[right]]++;

//         while (mp.size() > 2) {
//             mp[fruits[left]]--;

//             if (mp[fruits[left]] == 0) {
//                 mp.erase(fruits[left]);
//             }

//             left++;
//         }

//         maxLen = max(maxLen, right - left + 1);
//     }

//     return maxLen;
// }

// Time  = O(n) average
// Space = O(1)

    int totalFruit(vector<int>& fruits){
        //your code goes here
        int left = 0, right = 0;
        int maxLen = 0;
        int k = 2;
        map<int,int> mp;
        int n = fruits.size();

        while(right < n){
            mp[fruits[right]]++;

            if(mp.size() > k){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            if(mp.size() <= k){
                maxLen = max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3};

    cout << totalFruit(fruits) << endl;

    return 0;
}