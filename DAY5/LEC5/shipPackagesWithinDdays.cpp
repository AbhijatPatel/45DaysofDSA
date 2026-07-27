#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> & arr, int days, int capacity){
    int load = 0, dayCnt = 1;

    for(int i=0;i<arr.size();i++){
        if(load+arr[i]<=capacity){
            load += arr[i];
        }
        else{
            load = arr[i];
            dayCnt++;
        }
    }
    return dayCnt <= days;
}

int shipWithinDdays(vector<int> & weight, int days){
    int maxElm = *max_element(weight.begin(),weight.end());
    int sum = 0;
    int n = weight.size();

    for(int i=0;i<n;i++)
    sum += weight[i];

    int low = maxElm, high = sum;
    int ans = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(isPossible(weight,days,mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << shipWithinDdays(arr,days);
    return 0;
}