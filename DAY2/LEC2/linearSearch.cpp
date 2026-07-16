#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> & arr,int x){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==x)
        return i;
    }
    return -1;
}

int main() {
    vector<int> arr={3,5,7,8,1,16};
    int x=16;

   cout << linearSearch(arr,x);
    return 0;
} 