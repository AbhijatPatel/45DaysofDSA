#include <bits/stdc++.h>
using namespace std;

void arrangeNegpos(vector<int> & arr, int n){
    vector<int> Pos, Neg;

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            Neg.push_back(arr[i]);
        }
        else{
            Pos.push_back(arr[i]);
        }
    }
    for(int i=0;i<Pos.size();i++){
        arr[2*i]=Pos[i];
        arr[2*i+1]=Neg[i];
    }
}

int main() {
    vector<int> arr = {1,2,-3,-1,-2,3,-4};

    arrangeNegpos(arr,arr.size());

    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}