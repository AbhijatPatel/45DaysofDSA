#include <bits/stdc++.h>
using namespace std;

//linear search

// int findInsertPosition(vector<int> & arr, int n ,int k){

//     for(int i=0;i<n;i++){
//         if(arr[i]>k)
//         return i;
//     }
//     return -1;
// }


//Binary search

int findInsertPosition(vector<int> & arr, int n ,int k){
    int low = 0, high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == k)
        return mid;

        else if(arr[mid]< k){
        low = mid +1;
    }
     else{
        high = mid -1;
    }
}

    return low;
}

int main() {
    vector<int> arr = {1,2,4,7};
    int k = 6;

    cout << findInsertPosition(arr,arr.size(),k);
    return 0;
}