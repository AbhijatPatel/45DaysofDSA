#include <bits/stdc++.h>
using namespace std;

// bool isIsomorphic(string s, string t) {

//     if(s.size() != t.size())
//         return false;

//     int n = s.size();

//     for(int i = 0; i < n; i++) {

//         for(int j = 0; j < i; j++) {

//             if(s[i] == s[j] && t[i] != t[j])
//                 return false;

//             if(s[i] != s[j] && t[i] == t[j])
//                 return false;
//         }
//     }

//     return true;
// }


//optimized 
bool isIsomorphic(string s, string t) {

    if(s.size() != t.size())
        return false;

    vector<int> mapS(256,-1);
    vector<int> mapT(256,-1);

    for(int i = 0; i < s.size(); i++) {

        if(mapS[s[i]] != mapT[t[i]])
            return false;

        mapS[s[i]] = i;
        mapT[t[i]] = i;
    }

    return true;
}

int main() {

    cout << isIsomorphic("egg", "add");
}