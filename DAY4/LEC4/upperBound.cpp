#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> & arr, int n, int k){

    int ans = INT_MAX;
    int low = 0,  high = n-1;
    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] > k){
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr ={3,5,8,9,15,19};
    int k =9;
    
    cout << lowerBound(arr,arr.size(),k);
    return 0;
}