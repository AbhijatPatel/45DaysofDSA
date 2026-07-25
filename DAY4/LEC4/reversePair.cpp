#include <bits/stdc++.h>
using namespace std;

//brute force
// int reversePair(vector<int> & arr, int n){
//     int count = 0;

//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){

//             if(arr[i]>2*arr[j])
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

    for(int i=low;i<=mid;i++){
        while(j<=high && arr[i] > 2 * arr[j])
        j++;
        count +=(j-(mid+1));
    }

    i=low;
    j=mid+1;

    while(i<=mid && j<=high){
        if(arr[i]> arr[j]){

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

int reversePair(vector<int> & arr, int n){
    return mergeSort(arr,0,n-1);
}
//time complexity of O(n log n).
int main() {
    vector<int> arr = {1,3,2,3,1};

    cout << reversePair(arr,arr.size());
    return 0;
}