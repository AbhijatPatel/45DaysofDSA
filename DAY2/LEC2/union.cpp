#include <bits/stdc++.h>
using namespace std;

//using set

// void Union(vector<int> & arr1,vector<int> & arr2,int n,int m){
//     set<int>st;
//     for(int i=0;i<n;i++){
//         st.insert(arr1[i]);
//     }

//     for(int i=0;i<m;i++){
//         st.insert(arr2[i]);
//     }
//     for(auto it:st)
//     cout << it <<" ";
// }

//using two pointer approach

void Union(vector<int> & arr1,vector<int> & arr2,int n,int m){
    vector<int>ans;

    int i=0, j=0;
    while(i<n && j<m){
        if(arr1[i]>=arr2[j]){
            if(ans.size() == 0 || ans.back()!= arr2[j]){
                ans.push_back(arr2[j]);

            }
            j++;
        }
        else{
            if (ans.size() == 0 || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }

    }

    while(i<n){
        if(ans.back()!= arr1[i]){
            ans.push_back(arr1[i]);
            i++;
        }
    }

while(j<m){
        if(ans.back()!= arr2[j]){
            ans.push_back(arr2[j]);
            j++;
        }
    }
    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";
}



int main() {
    vector<int> arr1={3,8,12,15};
    vector<int> arr2={1,1,6,6,7,17};

    Union(arr1,arr2,arr1.size(),arr2.size());

    return 0;
}