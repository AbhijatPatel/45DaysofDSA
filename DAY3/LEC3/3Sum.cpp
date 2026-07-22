#include <bits/stdc++.h>
using namespace std;

// brute force
// void ThreeSum(vector<int> & arr, int n){
//     set<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){

//                 if(i!=j!=k && (arr[i]+arr[j]+arr[k] == 0)){
//                     vector<int> temp ={arr[i],arr[j],arr[k]};

//                     sort(temp.begin(),temp.end());
//                     ans.insert(temp);
//                 }
//             }
//         }
//     }
//     for(auto it : ans){
//             for(int i=0;i<it.size();i++){
//                 cout << it[i]<< " ";
//             }
//              cout << endl;
//         } 
//     }
//T.C =O(n^3) S.C=O(k)

//better approach

//  void ThreeSum(vector<int> & arr, int n){
//     set<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         set<int> st;
//         for(int j=i+1;j<n;j++){
//             int third = -(arr[i]+arr[j]);

//             if(st.find(third)!= st.end()){
//                 vector<int> temp={arr[i],arr[j],third};
//                 sort(temp.begin(), temp.end());
//                 ans.insert(temp);
//             }
//             st.insert(arr[j]);
//         }
//     }
//     for(auto it : ans){
//             for(int i=0;i<it.size();i++){
//                 cout << it[i]<< " ";
//             }
//              cout << endl;
//         }
//     }
//T.C =O(n^2logn) S.C = o(n)
//optimized approach

void ThreeSum(vector<int> & arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        if(i!=0 && arr[i]==arr[i-1])continue;

        int j=i+1;
        int k=n-1;

        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];

            if(sum<0){
                j++;
            }
            else if(sum>0)
            k--;

            else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j<k && arr[j] == arr[j-1])
                j++;

                while(j<k && arr[k] == arr[k+1])
                k--;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;
}
//T.C=O(n²) S.C=O(1)

int main() {
    vector<int> arr = {-1,0,1,2,-1,-4};

    ThreeSum(arr,arr.size());
    return 0;
}