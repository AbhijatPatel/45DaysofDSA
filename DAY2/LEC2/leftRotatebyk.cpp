#include <bits/stdc++.h>
using namespace std;

 void reverse(vector<int> & arr,int i,int j){
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
 }

void leftRotatebyk(vector<int> & arr,int n,int k){

//If k is greater than n, your code won't work correctly because it may access invalid indices.
 //Normalize k before performing the reversals,
 k = k % n;
 //otherwise ignore this,

    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
}
int main() {
    vector<int> arr={1,2,3,4,5,6,7};
    int k=9;

    leftRotatebyk(arr,arr.size(),k);
    return 0;
}