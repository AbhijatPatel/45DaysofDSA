#include <bits/stdc++.h>
using namespace std;

// int longestSubsequence(vector<int> & arr,int n){
//     int maxCount=1 , count = 0;
//     int series;

//     sort(arr.begin(), arr.end());
//     for(int i=0;i<n;i++){
//         series=arr[i];
//         count =1;

//         for(int j= i+1;j<n;j++){
//             cout << arr[j] << endl;
//             if(arr[j] == series+1){
//                 count++;
//                 series++;
//             }

//             maxCount = max(count,maxCount);
//                 if(j==n-1)
//                 return maxCount;
//             }
//         }
//         return maxCount;
// }

//optimal

 int longestSubsequence(vector<int> & arr,int n){

    if(n == 0)
    return 0;

    sort(arr.begin(),arr.end());

     int series = arr[0];
    int count = 1 , maxCount = 1;

    for(int i=1;i<n;i++){
        if(arr[i] == series+1){
        series=arr[i];
        count++;
    }
        
    else if(arr[i] != series){
        series=arr[i];
        count = 1;
    }
    
    maxCount=max(count,maxCount);
  }
  return maxCount;
}

int main() {
    vector<int> arr ={100,200,1,3,2,4};

    cout << longestSubsequence(arr,arr.size());
    return 0;
}