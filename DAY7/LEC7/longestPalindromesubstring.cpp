#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int maxLen = 0;
    int start = 0;
    int n = s.size();

    for(int c=0;c<n;c++){
        int l=c , r=c;

        //odd

        while(l>=0 && r<n && s[l] == s[r]){
            if(r-l+1>maxLen){
                start = l;
                maxLen = r-l+1;
            }
            l--;
            r++;
        }

        //even
        l=c;
        r=c+1;

         while(l>=0 && r<n && s[l] == s[r]){
            if(r-l+1>maxLen){
                start = l;
                maxLen = r-l+1;
            }
            l--;
            r++;
        }
    }
    return s.substr(start,maxLen);
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s);
    return 0;
}