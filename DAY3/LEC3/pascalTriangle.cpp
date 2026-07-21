#include <bits/stdc++.h>
using namespace std;

//brute
// int nCr(int n, int r){
//     long long res = 1;

//     for(int i=0;i<r;i++){
//         res = res*(n-i);
//         res = res/(i+1);
//     }
//     return (int)(res);
// }

// vector<vector<int>> pascalTriangle(int n){
//     vector<vector<int>> ans;

//     for(int row=1;row<=n;row++){
//         vector<int> temp;

//         for(int col=1;col<=row;col++){
//             temp.push_back(nCr(row-1,col-1));
//         }
//             ans.push_back(temp);
//         }
    
//     return ans;
// }

//optimized

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;

    for(int row = 1; row <= n; row++)
    {
        vector<int> temp;

        long long value = 1;

        for(int col = 1; col <= row; col++)
        {
            temp.push_back(value);

            value = value * (row - col);
            value = value / col;
        }

        ans.push_back(temp);
    }

    return ans;
}

int main() {
    int n = 10;
    vector<vector<int>> ans = pascalTriangle(n);

    for(int i = 0; i < ans.size(); i++)
{
    for(int j = 0; j < ans[i].size(); j++)
    {
        cout << ans[i][j] << " ";
    }
    cout << endl;
}
    return 0;
}
