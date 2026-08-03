#include <bits/stdc++.h>
using namespace std;

//(Split + Vector)
string reverseWords(string s) {

    vector<string> words;
    string temp = "";

    for(char ch : s){

        if(ch == ' '){

            if(temp != ""){
                words.push_back(temp);
                temp = "";
            }
        }
        else{
            temp += ch;
        }
    }

    if(temp != "")
        words.push_back(temp);

    string ans = "";

    for(int i = words.size()-1; i >= 0; i--){

        ans += words[i];

        if(i != 0)
            ans += " ";
    }

    return ans;
}

//Reverse Whole String + Reverse Each Word (Optimal)
// string reverseWords(string s) {

//     reverse(s.begin(), s.end());

//     int n = s.size();
//     int start = 0;

//     for(int end = 0; end <= n; end++){

//         if(end == n || s[end] == ' '){

//             reverse(s.begin() + start, s.begin() + end);

//             start = end + 1;
//         }
//     }

//     return s;
// }

int main(){

    string s = "the sky is blue";
    cout << reverseWords(s);
}