#include <bits/stdc++.h>
using namespace std;

// pair<int,int> findMissingDuplicate(vector<int> & arr, int n){
//     vector<int> ans;
//     sort(arr.begin(), arr.end());

//     for(int i=1;i<n;i++){
//         if(arr[i-1] != i){
//             return{arr[i-1],i};
//         }
//     }
//     return{-1,-1};
// }

 pair<int,int> findMissingDuplicate(vector<int> & arr, int n){

    int x = (n*(n+1))/2;
    int y = 0;

    for( int i=0;i<n;i++){
        y += arr[i];
    }

    int XminusY = x-y;

    int x2 =  (n*(n+1)*(2*n+1))/6;
    int y2 = 0;

    for(int i=0;i<n;i++){
        y2 += (arr[i]*arr[i]);
    }
    
    int X2minusY2 = x2-y2; 

    int XplusY = X2minusY2/XminusY;

    x = (XplusY + XminusY)/2;

    y = XplusY-x;

    return{y,x};
}

int main() {
    vector<int> arr = {3,1,2,5,3};

    pair<int,int> ans = findMissingDuplicate(arr,arr.size());
    cout << "Duplicate Number : "<<ans.first << endl;
    cout << "Missing Number : " << ans.second;
    return 0;
}