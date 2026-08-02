#include <bits/stdc++.h>
using namespace std;


//brute force Time : O(N*M log(N*M))
//Space: O(N*M)
// int matrixMedian(vector<vector<int>> &mat)
// {
//     vector<int> temp;

//     int n = mat.size();
//     int m = mat[0].size();

//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             temp.push_back(mat[i][j]);
//         }
//     }

//     sort(temp.begin(), temp.end());

//     return temp[(n * m) / 2];
// }

//better Time : O(log(Max-Min) × N × logM)
//Space: O(1)

// int matrixMedian(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();

//     int low = INT_MAX;
//     int high = INT_MIN;

//     for(int i = 0; i < n; i++)
//     {
//         low = min(low, mat[i][0]);
//         high = max(high, mat[i][m - 1]);
//     }

//     int required = (n * m) / 2;

//     while(low <= high)
//     {
//         int mid = (low + high) / 2;

//         int count = 0;

//         for(int i = 0; i < n; i++)
//         {
//             count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
//         }

//         if(count <= required)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }

//     return low;
// }

//optimized
// int countSmallerEqual(vector<int> &row, int x)
// {
//     int low = 0;
//     int high = row.size() - 1;
//     int ans = row.size();

//     while(low <= high)
//     {
//         int mid = (low + high) / 2;

//         if(row[mid] > x)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }

//     return ans;
// }

// int matrixMedian(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     int m = mat[0].size();

//     int low = INT_MAX;
//     int high = INT_MIN;

//     for(int i = 0; i < n; i++)
//     {
//         low = min(low, mat[i][0]);
//         high = max(high, mat[i][m - 1]);
//     }

//     int required = (n * m) / 2;

//     while(low <= high)
//     {
//         int mid = (low + high) / 2;

//         int count = 0;

//         for(int i = 0; i < n; i++)
//         {
//             count += countSmallerEqual(mat[i], mid);
//         }

//         if(count <= required)
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }

//     return low;
// }


int upperBound(vector<int> &arr, int x, int m)
{
    int low = 0;
    int high = m - 1;
    int ans = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cnt += upperBound(matrix[i], x, m);
    }

    return cnt;
}

int medianMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int smallEqual = countSmallEqual(matrix, n, m, mid);

        if (smallEqual <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    vector<vector<int>> matrix =
    {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Median = " << medianMatrix(matrix);

    return 0;
}