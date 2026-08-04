#include <bits/stdc++.h>
using namespace std;

//brute counter/one pass

// int maxDepth(string s)
// {
//     int depth = 0;
//     int maxDepth = 0;

//     for(int i = 0; i < s.size(); i++)
//     {
//         if(s[i] == '(')
//         {
//             depth++;
//             maxDepth = max(maxDepth, depth);
//         }
//         else if(s[i] == ')')
//         {
//             depth--;
//         }
//     }

//     return maxDepth;
// }

//optimized stack

int maxDepth(string s)
{
    stack<char>st;
    int maxDepth = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
            maxDepth = max(maxDepth, (int)st.size());
        }
        else if(s[i] == ')')
        {
            st.pop();
            
        }
    }

    return maxDepth;
}
int main()
{
    string s = "(1+(2*3)+((8)/4))+1";

    cout << "Maximum Depth = " << maxDepth(s);

    return 0;
}