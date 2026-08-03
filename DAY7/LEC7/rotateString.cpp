#include <bits/stdc++.h>
using namespace std;

// bool rotateString(string s, string goal){
//     if(s.size() != goal.size())
//     return false;

//     int n = s.size();
//     for(int i=0;i<n;i++){
//         string rotate = s.substr(i+1) + s.substr(0,i+1);

//         if(rotate == goal)
//         return true;
//     }
//     return false;
// }

//optimal concatinate

bool rotateString(string s, string goal){
    if(s.size() != goal.size())
    return false;

    string temp =  s+s;

    return temp.find(goal) != string::npos;
}
int main() {
    cout << rotateString("abcde","cdeab");
    return 0;
}