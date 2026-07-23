#include <bits/stdc++.h>
using namespace std;

// void mergeIntervals(vector<vector<int>> & arr,int n){
//     int iStart =arr[0][0];
//     int iEnd = arr[0][1];
//     vector<vector<int>> ans;

//     for(int i=1;i<n;i++){
//         if(arr[i][0] < iEnd){
//             iEnd = max(iEnd,arr[i][1]);
//         }

//         else {
//             ans.push_back({iStart,iEnd});
//             iStart = arr[i][0];
//             iEnd = arr[i][1];
//         }
//     }

//     if(ans.back()[1] != iEnd){
//         ans.push_back({iStart,iEnd});
//     }
//     for(int i=0;i<ans.size();i++){
//         cout << "[" << ans[i][0] << "," <<ans[i][1] << "]" << endl;
//     }
// }


void mergeIntervals(vector<vector<int>> &arr, int n)
{
    if (n == 0)
        return;

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    int iStart = arr[0][0];
    int iEnd = arr[0][1];

    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] <= iEnd)
        {
            iEnd = max(iEnd, arr[i][1]);
        }
        else
        {
            ans.push_back({iStart, iEnd});

            iStart = arr[i][0];
            iEnd = arr[i][1];
        }
    }


    ans.push_back({iStart, iEnd});

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]" << endl;
    }
}


int main() {
    vector<vector<int>> arr = {{1,3}, {2,6},{8,10},{15,18}};

    mergeIntervals(arr,arr.size());
    return 0;
}