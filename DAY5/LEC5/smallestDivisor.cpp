#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> & arr, int threshold, int div){
    int sum = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        sum +=((arr[i]+div-1)/div);   
    }
         if(sum <= threshold)
         return true;

         return false;
     
}

int smallestDivisor(vector<int> & arr, int threshold){
     int maxElm = *max_element(arr.begin(), arr.end());

     int ans = -1;
     if(arr.size()>threshold)
     return -1;

     int low = 1, high = maxElm;

     while(low<=high){
        int mid = (low+high)/2;

        if(isPossible(arr,threshold,mid)){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
     }
     return ans;
}

int main() {
    vector<int> arr = {8,4,2};
    int threshold = 6;

    cout << smallestDivisor(arr,threshold);
    return 0;
}