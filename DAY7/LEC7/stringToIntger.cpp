#include <bits/stdc++.h>
using namespace std;

// int myAtoi(string s)
// {
//     int i = 0;
//     int sign = 1;
//     int ans = 0;

//     while(i < s.size() && s[i] == ' ')
//     {
//         i++;
//     }
//     if(s[i] == '-')
//     {
//         sign = -1;
//         i++;
//     }
//     else if(s[i] == '+')
//     {
//         i++;
//     }

//     while(i < s.size() && isdigit(s[i]))
//     {
//         int digit = s[i] - '0';

//         ans = ans * 10 + digit;

//         i++;
//     }

//     return ans * sign;
// }

int myAtoi(string s)
{
    int i = 0;
    int n = s.size();

    while(i < n && s[i] == ' ')
    {
        i++;
    }

    int sign = 1;

    if(i < n && s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(i < n && s[i] == '+')
    {
        i++;
    }

    long long ans = 0;

    while(i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        ans = ans * 10 + digit;

        // if(sign == 1 && ans > INT_MAX)
        // {
        //     return INT_MAX;
        // }

        // if(sign == -1 && -ans < INT_MIN)
        // {
        //     return INT_MIN;
        // }

        if(ans > (INT_MAX-digit)/10)
        return sign ==  1 ? INT_MAX: INT_MIN;
        i++;
    }

    return sign * ans;
}

int main()
{
    string s = "  -123abc";

    cout << myAtoi(s);

    return 0;
}