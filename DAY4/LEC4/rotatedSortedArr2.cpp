#include <bits/stdc++.h>
using namespace std;

bool rotatedSortedArray(vector<int> & arr, int n, int k){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid ] == k)
        return true;

        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++, high--;
            continue;
        }
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
                if(k>arr[mid] && k<=arr[high]){
                low = mid +1;
            }
            
            else
            {
                high = mid-1;
            }
        }
    }
    return false;
}

int main() {
    vector<int> arr = {7,8,1,2,3,3,3,4,5,6};
    int k = 3;

    cout << rotatedSortedArray(arr,arr.size(),k);
    return 0;
}