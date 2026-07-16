#include <bits/stdc++.h>
using namespace std;

int secondlargestElm(vector<int> & arr,int n){
    int largestElm=arr[0] , scndlargestElm=-1;

    for(int i=0;i<n;i++){
        if(arr[i]>largestElm){
            scndlargestElm=largestElm;
            largestElm=arr[i];
        }
        else if(arr[i] !=largestElm && arr[i]>scndlargestElm){
            scndlargestElm=arr[i];
        }
    }
    return scndlargestElm;
}

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << secondlargestElm(arr,n);
    return 0;
}