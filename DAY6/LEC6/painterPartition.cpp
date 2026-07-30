#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> & arr, int k , int maxTime){
    int currTime= 0;
    k--;

    for(int i=0;i<arr.size();i++){
        if(currTime + arr[i] <= maxTime){
            currTime += arr[i];
        }

        else {
            currTime= arr[i];
            k--;
        }
    }
    if(k<0)
    return false;

    return true;
}
int paintersPartition(vector<int> & arr, int k){
    
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
    
    cout<< paintersPartition(arr,k); 
    return 0;
}