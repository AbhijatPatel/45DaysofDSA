#include <bits/stdc++.h>
using namespace std;

//better approach T.C=O(n*m
// vector<int> findPeakElm(vector<vector<int>>& mat)
// {
//     int n=mat.size();
//     int m=mat[0].size();

//     for(int i=0;i<n;i++)
//     {
//         int col=0;

//         for(int j=1;j<m;j++)
//         {
//             if(mat[i][j]>mat[i][col])
//                 col=j;
//         }

//         int up=(i==0)?-1:mat[i-1][col];
//         int down=(i==n-1)?-1:mat[i+1][col];

//         if(mat[i][col]>up && mat[i][col]>down)
//             return {i,col};
//     }

//     return {-1,-1};
// }

//optimized T.C= O(nlogm)
// int maxRow(vector<vector<int>>& mat,int col)
// {
//     int row=0;

//     for(int i=1;i<mat.size();i++)
//     {
//         if(mat[i][col]>mat[row][col])
//             row=i;
//     }

//     return row;
// }

// vector<int> findPeakElm(vector<vector<int>>& mat)
// {
//     int n=mat.size();
//     int m=mat[0].size();

//     int low=0;
//     int high=m-1;

//     while(low<=high)
//     {
//         int mid=(low+high)/2;

//         int row=maxRow(mat,mid);

//         int left=(mid==0)?-1:mat[row][mid-1];
//         int right=(mid==m-1)?-1:mat[row][mid+1];

//         if(mat[row][mid]>left &&
//            mat[row][mid]>right)
//         {
//             return {row,mid};
//         }

//         else if(left>mat[row][mid])
//         {
//             high=mid-1;
//         }

//         else
//         {
//             low=mid+1;
//         }
//     }

//     return {-1,-1};
// }

//optimal (biggner friendly) T.c = O(nlogm)
#include <bits/stdc++.h>
using namespace std;

int maxRow(vector<vector<int>> &mat, int col)
{
    int row = 0;

    for (int i = 1; i < mat.size(); i++)
    {
        if (mat[i][col] > mat[row][col])
        {
            row = i;
        }
    }

    return row;
}

vector<int> findPeakElm(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int row = maxRow(mat, mid);

        int left;
        if (mid == 0)
            left = -1;
        else
            left = mat[row][mid - 1];

        int right;
        if (mid == m - 1)
            right = -1;
        else
            right = mat[row][mid + 1];

        int curr = mat[row][mid];

        if (curr > left && curr > right)
        {
            return {row, mid};
        }
        else if (left > curr)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}
int main()
{
    vector<vector<int>> mat={
        {10,20,15,2},
        {21,30,14,5},
        {7,16,32,4}
    };

    vector<int> ans=findPeakElm(mat);

    cout<<ans[0]<<" "<<ans[1];
}