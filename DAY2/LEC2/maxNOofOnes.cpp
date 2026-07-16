#include <bits/stdc++.h>
using namespace std;

int findMaxNoofOnes(vector<int> & arr, int n){
    int maxOnes = 0 , currentCount = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            currentCount++;
        maxOnes = max(currentCount , maxOnes);
        }

        
        else{
            maxOnes = max(currentCount , maxOnes);
            currentCount = 0;
       }

    }
    return maxOnes;

}

int main() {
    vector<int> arr = {1,1,0,1,1,1};

    cout << findMaxNoofOnes(arr,arr.size());
    return 0;
}