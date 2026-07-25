#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> & arr, int n, int k){

    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k)

        return mid;

        else if (arr[mid] > k){
            high = mid -1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,4,5,6,7,8,14,17};
    int k = 7;

    cout << binarySearch(arr, arr.size(),k);
    return 0;
}