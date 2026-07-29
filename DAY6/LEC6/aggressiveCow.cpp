#include <bits/stdc++.h>
using namespace std;

//linear search

// bool canPlaceCow(vector<int> & stalls, int k, int d){
//     k--;
//     int lastcow = stalls[0];
//     for(int i=0;i<stalls.size();i++){
//         if(stalls[i]-lastcow >= d){
//             lastcow = stalls[i];
//             k--;

//             if(k==0)
//             return true;
//         }
//     }
//     return false;
// }

// int aggressiveCow(vector<int> & stalls,int k){
//     int n = stalls.size();

//     if(n<k)//(stall.size < cow)
//     return n-1;

//     sort(stalls.begin(),stalls.end());

//     int last =  stalls[n-1]-stalls[0];
//     for(int i=0;i<stalls.size();i++){

//         if (canPlaceCow(stalls,k,i) == false)
//         return i-1;
//     }
//     return last;
// }

//binary search

bool canPlaceCow(vector<int> & stalls, int k, int d){
    k--;
    int lastcow = stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastcow >= d){
            lastcow = stalls[i];
            k--;

            if(k==0)
            return true;
        }
    }
    return false;
}

int aggressiveCow(vector<int> & stalls,int k){
    int n = stalls.size();

    if(n<k)//(stall.size < cow)
    return n-1;

    sort(stalls.begin(),stalls.end());

    int last =  stalls[n-1]-stalls[0];
    int low = 1, high = last;

    while(low<=high){
        int mid = (low+high)/2;

        if(canPlaceCow(stalls,k,mid))
        low = mid+1;
        else
        high= mid -1;
    }
    return high;
}
int main() {
    vector<int> stalls  = {1,2,4,8,9};
    int k = 3;

    cout << aggressiveCow(stalls,k);
    return 0;
}