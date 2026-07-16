
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> & arr, int n){
    int sum = 0;
    int maxSum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];

        maxSum = max(maxSum,sum);

        if(sum < 0){
            sum =0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubarraySum(arr,arr.size());
    return 0;
}