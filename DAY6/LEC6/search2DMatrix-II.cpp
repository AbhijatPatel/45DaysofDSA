#include <bits/stdc++.h>
using namespace std;

//brute force T.C = o(n*m)
// bool searchMatrix(vector<vector<int>>& matrix, int target)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]==target)
//                 return true;
//         }
//     }

//     return false;
// }

// bs on every row T.C=O(nlogm)

// bool BS(vector<int>& arr,int target)
// {
//     int low=0;
//     int high=arr.size()-1;

//     while(low<=high)
//     {
//         int mid=(low+high)/2;

//         if(arr[mid]==target)
//             return true;

//         else if(arr[mid]<target)
//             low=mid+1;

//         else
//             high=mid-1;
//     }

//     return false;
// }

// bool searchMatrix(vector<vector<int>>& matrix,int target)
// {
//     int n=matrix.size();

//     for(int i=0;i<n;i++)
//     {
//         if(BS(matrix[i],target))
//             return true;
//     }

//     return false;
// }

// bs on every col T.C=O(mlogn)

// bool searchMatrix(vector<vector<int>>& matrix,int target)
// {
//     int n=matrix.size();
//     int m=matrix[0].size();

//     for(int col=0;col<m;col++)
//     {
//         int low=0;
//         int high=n-1;

//         while(low<=high)
//         {
//             int mid=(low+high)/2;

//             if(matrix[mid][col]==target)
//                 return true;

//             else if(matrix[mid][col]<target)
//                 low=mid+1;

//             else
//                 high=mid-1;
//         }
//     }

//     return false;
// }


//staircase search case T.C = o(n+m)
bool searchMatrix(vector<vector<int>>& matrix,int target)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int row=0;
    int col=m-1;

    while(row<n && col>=0)
    {
        if(matrix[row][col]==target)
            return true;

        else if(matrix[row][col]>target)
            col--;

        else
            row++;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix={
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    int target=14;

    if(searchMatrix(matrix,target))
        cout<<"Found";
    else
        cout<<"Not Found";
}