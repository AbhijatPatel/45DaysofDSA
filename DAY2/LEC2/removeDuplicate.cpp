#include <bits/stdc++.h>
using namespace std;

void removeDuplicate(vector<int> & arr, int n){
    int i=0;
    int j=0;

    while(j<n){
        while(j<n && arr[i] == arr[j])
        j++;
        if(j>=n)
        break;
        
        else{
            i++;
            arr[i]=arr[j];
        }
    }

    for(int k=0; k<=i; k++){
        cout << arr[k] << " ";
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    removeDuplicate(arr,n);
    return 0;
}