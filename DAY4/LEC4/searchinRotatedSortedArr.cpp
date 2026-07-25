#include <bits/stdc++.h>
using namespace std;

int findinRotatedArray(vector<int> & arr, int n, int k){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k)
        return mid;

        //left half sorted
        if(arr[low] <= arr[mid]){
            if(k>=arr[low] && k<=arr[mid]){
                high = mid-1;
            }
            else {
                low = mid +1;
            }
        }

        // right half sorted
            else 
            {
                if(k>=arr[mid] && k<=arr[high]){
                low = mid +1;
            }
            
            else
            {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2,3};
    int k = 0;

    cout << findinRotatedArray(arr,arr.size(),k);
    return 0;
}