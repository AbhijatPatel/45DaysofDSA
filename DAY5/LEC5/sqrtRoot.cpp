#include <bits/stdc++.h>
using namespace std;

//brute force

// int findSqrtRoot(int n){
//     int ans = 1;

//     for(int i=1;i<=n;i++){
//         if(i*i == n)
//         return i;

//          else if(i*i < n){
//         ans = i;
//     }
//     else{
//             break;
//         }
//     }
//     return ans;
// }

//optimized approach

int findSqrtRoot(int n){
    int low = 1, high = n;

    while(low<=high){
        int mid = (low+high)/2;

        if(mid*mid == n)
        return mid;

        else if(mid*mid > n)
            high = mid-1;

        else 
            low = mid+1;
    }
    return high;
}

int main() {
    int n;
    cin >> n;

    cout << findSqrtRoot(n);
    return 0;
}