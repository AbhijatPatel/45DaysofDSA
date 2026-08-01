#include <bits/stdc++.h>
using namespace std;

//brute force

// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == target)
//                 return true;
//         }
//     }

//     return false;
// }

//better approach
// bool BS(vector<int> &arr, int n, int target)
// {
//     int low = 0;
//     int high = n - 1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (arr[mid] == target)
//             return true;

//         else if (arr[mid] < target)
//             low = mid + 1;

//         else
//             high = mid - 1;
//     }

//     return false;
// }

// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for (int i = 0; i < n; i++)
//     {
    
//         if (target >= matrix[i][0] && target <= matrix[i][m - 1])
//         {
//             return BS(matrix[i], m, target);
//         }
//     }

//     return false;
// }

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}



int main()
{
    vector<vector<int>> matrix =
    {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 30;

    if (searchMatrix(matrix, target))
        cout << "Found";
    else
        cout << "Not Found";
}