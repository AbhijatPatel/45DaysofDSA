#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> & arr, int n, int k){
    int first = -1;
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k){
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] < k){
            low = mid+1;
        }
        else {
            high = mid -1;
        }
    }
    return first;
}

int lastOccurence(vector<int> & arr, int n, int k){
    int last = -1;
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] < k){
            low = mid+1;
        }
        else {
            high = mid -1;
        }
    }
    return last;
}

int main() {
    vector<int> arr = {3,4,13,13,13,20,40};
    int k = 13;

    int f = firstOccurence(arr, arr.size(),k);
    int l = lastOccurence(arr, arr.size(),k);

    cout <<(l-f+1);
    return 0;
}