#include <bits/stdc++.h>
 using namespace std;
 
 void reverse(vector<int> & arr,int i,int j){
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
 }

void rightRotatebyk(vector<int> & arr,int n,int k){
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
}
int main() {
    vector<int> arr={1,2,3,4,5,6,7};
    int k = 2;
    rightRotatebyk(arr,arr.size(),k);
    return 0;
}