#include <bits/stdc++.h>
using namespace std;

//brute force approach
// void leftRotateby1(vector<int> & arr,int n){
//     int temp =arr[0];

//     for(int i=0;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     arr[n-1]=temp;

//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
// }

//optimized approach
 void reverse(vector<int> & arr,int i,int j){
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
 }

void leftRotateby1(vector<int> & arr,int n){
    reverse(arr,0,0);
    reverse(arr,1,n-1);
    reverse(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
}
int main() {
    vector<int> arr={3};

    leftRotateby1(arr,arr.size());
    return 0;
}