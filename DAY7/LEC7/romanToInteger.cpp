#include <bits/stdc++.h>
using namespace std;

// int romanToInt(string s){
//     int ans = 0;
//     map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

//     for(int i=0;i<s.size();i++){
//         if(i+1 <s.size() &&  mp[s[i]]<mp[s[i+1]]){
//             ans -= mp[s[i]];
//         }
//         else{
//             ans += mp[s[i]];
//         }
//     }
//     return ans;
// }
// using switch case

int value(char ch)
{
    switch(ch)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
    int romanToInt(string s){
    int ans = 0;


    for(int i=0;i<s.size();i++){
        if(i+1 <s.size() &&  value(s[i])<value(s[i+1])){
            ans -= value(s[i]);
        }
        else{
            ans += value(s[i]);
        }
    }
    return ans;
}

int main() {
    string s = "MCMXCIV";
    cout << romanToInt(s);
    return 0;
}