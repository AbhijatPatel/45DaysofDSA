#include <bits/stdc++.h>
using namespace std;

//brute force approach
// void sort012(vector<int> &arr, int n){
//     sort(arr.begin(), arr.end());
// }

//Dutch national flag 

void sort012(vector<int> &arr, int n) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {

        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if (arr[mid] == 1) {
            mid++;
        }

        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


int main() {
    vector<int> arr = { 2,0,2,1,1,0};

    sort012(arr,arr.size());
    
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }

    return 0;
}