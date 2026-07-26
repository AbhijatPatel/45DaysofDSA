#include <bits/stdc++.h>
using namespace std;

int singleElmSortedArr(vector<int> & arr,int n){

    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
            return arr[mid];
        

            else  if(arr[mid] == arr[mid-1]){
                
                if((mid-1) % 2 ==  0)
                low = mid+1;

                else
                high = mid-1;
            }
            else if(arr[mid] == arr[mid+1]){
                if((mid) % 2 == 0)
                low = mid+1;

                else
                high = mid-1;
            }
        }
        return -1;
    }

int main() {
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5,6};

    cout << singleElmSortedArr(arr,arr.size());
    return 0;
}