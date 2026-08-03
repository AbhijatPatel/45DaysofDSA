#include <bits/stdc++.h>
using namespace std;

// bool isAnagram(string  s, string t){

//        if(s.size() != t.size())
//         return false;

//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());

//     return s==t;
// }

// two frequency array 


// bool isAnagram(string s, string t)
// {
//     if(s.size() != t.size())
//         return false;

//     int freqS[26] = {0};
//     int freqT[26] = {0};

//     for(int i = 0; i < s.size(); i++)
//     {
//         freqS[s[i] - 'a']++;
//         freqT[t[i] - 'a']++;
//     }

//     for(int i = 0; i < 26; i++)
//     {
//         if(freqS[i] != freqT[i])
//             return false;
//     }

//     return true;
// }

//frequect array lower case 
bool isAnagram(string s, string t)
{
    if(s.size() != t.size())
        return false;

    int freq[26] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++)
    {
        if(freq[i] != 0)
            return false;
    }

    return true;
}

int main() {
    cout << isAnagram("anagram","nagaram");
    return 0;
}