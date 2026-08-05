#include <bits/stdc++.h>
using namespace std;

// int getBeauty(string sub)
// {
//     int freq[26] = {0};

//     for(int i = 0; i < sub.size(); i++)
//     {
//         freq[sub[i] - 'a']++;
//     }

//     int maxi = 0;
//     int mini = INT_MAX;

//     for(int i = 0; i < 26; i++)
//     {
//         if(freq[i] > 0)
//         {
//             maxi = max(maxi, freq[i]);
//             mini = min(mini, freq[i]);
//         }
//     }

//     return maxi - mini;
// }

// int beautySum(string s)
// {
//     int ans = 0;

//     for(int i = 0; i < s.size(); i++)
//     {
//         for(int j = i; j < s.size(); j++)
//         {
//             string sub = s.substr(i, j - i + 1);

//             ans += getBeauty(sub);
//         }
//     }

//     return ans;
// }

//optimized 

int beautySum(string s)
{
    int ans = 0;
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        int freq[26] = {0};

        for(int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int maxi = 0;
            int mini = INT_MAX;

            for(int k = 0; k < 26; k++)
            {
                if(freq[k] > 0)
                {
                    maxi = max(maxi, freq[k]);
                    mini = min(mini, freq[k]);
                }
            }

            ans += maxi - mini;
        }
    }

    return ans;
}

int main()
{
    string s = "aabcb";

    cout << "Beauty Sum = " << beautySum(s);

    return 0;
}