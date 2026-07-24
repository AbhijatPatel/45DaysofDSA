#include <bits/stdc++.h>
using namespace std;

// void mergeTwoArr(vector<int> & arr1,vector<int> & arr2, int n, int m){
//     vector<int> ans(n+m);

//     int i=0, j=0, k=0;
//     while(i<n && j<m){
//         if(arr1[i]<arr2[j]){
//             ans[k]=arr1[i];
//             i++;
//         }

//         else {
//             ans[k]=arr2[j];
//             j++;
//         }
//         k++;
//     }
//     while(i<n){
//         ans[k]=arr1[i];
//         i++;
//         k++;
//     }
//     while(j<m){
//         ans[k]=arr2[j];
//         j++;
//         k++;
//     }
//     for(int i=0;i<ans.size();i++){
//         cout << ans[i] << " ";
//     }

// }

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)


//without extra space

void mergeTwoArr(vector<int> & arr1,vector<int> & arr2, int n, int m){
    int i =n-1, j=0;

    while(i>=0 && j<m){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }
        else {
            break;
        }
    }

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    
    for(int i=0;i<n;i++){
        cout << arr1[i] << " ";
    }
    for(int j=0;j<m;j++){
        cout << arr2[j] << " ";
    }
}
int main() {
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {2,4,6,8};

    int n = arr1.size();
    int m = arr2.size();

    mergeTwoArr(arr1,arr2,n,m);
    return 0;
}