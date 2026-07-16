#include <bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int> & arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    if(checkSorted(arr,n)){

        cout << "The given array is sorted" << endl;
    }

    else{
            cout << "The given array is not sorted" << endl;
        }
    
    return 0;
}