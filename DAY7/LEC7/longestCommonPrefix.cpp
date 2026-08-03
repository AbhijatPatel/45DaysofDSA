#include <bits/stdc++.h>
using namespace std;

// string longestCommonPrefix(vector<string> & strs){
//     string prefix = "";

//     for(int i=0;i<strs[0].size();i++){
//         char ch = strs[0][i];

//         for(int j=0;j<strs.size();j++){
//             if(i >= strs[j].size() || strs[j][i] != ch)
//             return prefix;
//         }
//         prefix +=ch;
//     }
//     return prefix;
// }

//optimal

string longestCommonPrefix(vector<string> & strs){
    string prefix = "";

    sort(strs.begin(),strs.end());
    int n = strs.size();

    for(int i=0;i<strs[0].size();i++){
        char ch = strs[0][i];

        for(int j=0;j<strs.size();j++){
            if(i >= strs[j].size() || strs[j][i] != ch)
            return prefix;
        }
        prefix +=ch;
    }
    return prefix;
}
int main() {
    vector<string> strs = {"flower","flow","flight"};

    cout << longestCommonPrefix(strs);
    return 0;
}