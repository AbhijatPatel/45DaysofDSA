#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> & arr,int n){
    int count = 1;
    for(int i=0;i<n;i++){
        if(arr[i] == count)
        count++;

        else
        return count;
    }
    return count;
}

int main() {
    vector<int> arr ={1,3,4,5};

    cout << findMissingNumber(arr,arr.size());
    return 0;
}