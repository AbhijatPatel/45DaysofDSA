#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> & arr, int k , int maxPage){
    int pageCnt = 0;
    k--;

    for(int i=0;i<arr.size();i++){
        if(pageCnt + arr[i] <= maxPage){
            pageCnt += arr[i];
        }

        else {
            pageCnt = arr[i];
            k--;
        }
    }
    if(k<0)
    return false;

    return true;
}
int bookAllocation(vector<int> & arr, int k){
    
    int maxElm = *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(),arr.end(),0);

    if(k>arr.size())
    return -1;
    int low = maxElm, high = sum;
    while(low<=high){
        int mid = (low+high)/2;

        if(isPossible(arr,k,mid))
        high = mid-1;

        else
        low = mid+1;
    }
    return low;
}


int main() {
    vector<int> arr = {10,20,30,40};
    int k = 2;
    
    cout<< bookAllocation(arr,k); 
    return 0;
}