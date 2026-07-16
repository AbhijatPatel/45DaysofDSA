#include <bits/stdc++.h>
using namespace std;

int largestElm(int arr[],int n){
    int largestE=arr[0];

    for(int i=0;i<n;i++){
        largestE=max(largestE,arr[i]);
    }
    return largestE;
}

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << largestElm(arr,n);
    return 0;
}