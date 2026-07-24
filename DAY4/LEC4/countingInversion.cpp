#include <bits/stdc++.h>
using namespace std;

//brute force
// int countinversion(vector<int> & arr, int n){
//     int count = 0;

//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i] > arr[j])
//             count++;
//         }
//     }
//     return count;
// }


//optimized approach

int merge(vector<int> & arr, int low, int mid, int high){
    int i = low;
    int j = mid+1;

    vector<int> temp;
    int count = 0;

    while(i<=mid && j<=high){
        if(arr[i]> arr[j]){
            count += (mid-i+1);
            temp.push_back(arr[j]);
            j++;
        }

         else {
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        for(int i =low;i <=high;i++){
            arr[i] = temp[i-low];
        }
        return count;
    }
int mergeSort(vector<int> & arr, int low, int high){
    if(low>=high)
    return 0;

    int mid = (low + high)/2;
    int count = 0;

    count += mergeSort(arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += merge(arr,low,mid,high);
    return count;
}

void countinversion(vector<int> & arr, int n){
    cout << mergeSort(arr,0,n-1);
}

int main() {
    vector<int> arr = {5,3,2,1,4};

    countinversion(arr,arr.size());
    return 0;
}