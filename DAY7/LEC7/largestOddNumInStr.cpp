#include <bits/stdc++.h>
using namespace std;

// string largestOddNumber(string num){
//     int n = num.size();
//     int i = n-1;

//     while(i>=0){
//         if(num[i] % 2 != 0){
//             break;
//         }
//         i--;
//     }
//     if(i<0)
//     return "";

//     return  num.substr(0,i+1);
// } 

//optimal right to left


// string largestOddNumber(string num) {

//     int n = num.size();
//     int i = n - 1;

//     while(i >= 0) {

//         if((num[i] - '0') % 2 != 0) {
//             break;
//         }

//         i--;
//     }

//     if(i < 0)
//         return "";

//     return num.substr(0, i + 1);
// }

//Left to Right (Store the Last Odd Index

string largestOddNumber(string num) {

    int lastOdd = -1;

    for(int i = 0; i < num.size(); i++) {

        if((num[i] - '0') % 2 == 1) {
            lastOdd = i;
        }
    }

    if(lastOdd == -1)
        return "";

    return num.substr(0, lastOdd + 1);
}
int main() {
        string num = "354270";

    cout << "Largest Odd Number = " << largestOddNumber(num);
    return 0;
}