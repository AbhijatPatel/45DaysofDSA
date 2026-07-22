#include <bits/stdc++.h>
using namespace std;

void fourSum(vector<int> & arr, int n,int target){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;

        for(int j=i+1;j<n;j++){

            if(j>i+1 && arr[j]==arr[j-1])continue;

            int k=j+1;
            int l=n-1;

            while(k<l){
                long long sum =arr[i]+arr[j]+arr[k]+arr[l];

                if(sum==target){
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while(k<l && arr[k] == arr[k-1])
                    k++;
                    while(k<l && arr[l] == arr[l+1])
                    l--;
                }
                else if(sum < target)
                k++;

                else
                l--;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;

    fourSum(arr,arr.size(),target);
    return 0;
}