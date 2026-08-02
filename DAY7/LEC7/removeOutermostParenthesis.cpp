#include <bits/stdc++.h>
using namespace std;

//brute force  

// string removeOutermostParenthesis(string s){
//     string ans = "";

//     stack<char>st;
//     for(int i=0;i<s.size();i++){
//         char ch = s[i];
//         if(ch == '('){
//             if(!st.empty())
//             ans += ch;
//             st.push(ch);
//         }
//         else{
//             st.pop();
//             if(!st.empty())ans += ch;
//         }
//     }
//     return ans;
// }

//better approach
// string removeOutermostParenthesis(string s){
//     string ans = "";
//     string temp  = "";

//     int cnt  = 0;
//     for(int i=0;i<s.size();i++){
//         char ch = s[i];
//         temp +=  ch;

//         if(ch == '(')
//         cnt++;
//         else
//         cnt--;

//         if(cnt == 0){
//             ans += temp.substr(1,temp.size()-2);
//             temp =  "";
//         }
//     }
//     return ans;
// }

//optimized approach (Pre-Increment / Post-Decrement)

string removeOutermostParenthesis(string s){
    string ans = "";
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch == '('){
            if(cnt > 0)
            ans += ch;
            cnt++;
        }
        else{
            cnt--;
            if(cnt > 0)
            ans += ch;
        }
    }
    return ans;
}
int main() {
    string s = "(()())(())";
    cout << removeOutermostParenthesis(s);
    return 0;
}