#include <bits/stdc++.h>
using namespace std;

//brute force
// int peakElm(vector<int> & arr,int n){
//     if(arr[0] >arr[1])
//     return 0;

//     if(arr[n-1]>arr[n-1])
//     return n-1;

//     for(int i=0;i<n-1;i++){
//         if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
//         return i;
//     }
//     return -1;
// }

//optimized approach

int peakElm(vector<int> & arr, int n){
    int low = 0, high =  n-1;
    
    if(arr[0]>arr[1])
    return 0;

    if(arr[n-1]>arr[n-2])
    return n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]>arr[mid+1] && arr[ mid]>arr[mid-1])
         return mid;

            else  if(arr[mid] > arr[mid-1])
                low = mid+1;
            
            else 
                high = mid-1;
            
        }
        return -1;
    }


int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,5,1};

    cout << peakElm(arr,arr.size());
    return 0;
}