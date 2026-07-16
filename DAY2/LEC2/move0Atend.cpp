#include <bits/stdc++.h>
using namespace std;

void moveZeroToEnd(vector<int> & arr , int n){
    int i=0;

    while(i<n){
        while(i<n && arr[i] != 0)
        i++;

        int j=i+1;
        if(j>=n)
        break;
        while(j<n && arr[j] == 0)
        j++;
        
        if(j<n){
            swap(arr[i],arr[j]);
        }
        i++;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
}

int main() {
    vector<int> arr={1,0,2,3,0,0,4,0};

    moveZeroToEnd(arr,arr.size());
    return 0;
}