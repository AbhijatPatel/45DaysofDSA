#include <bits/stdc++.h>
using namespace std;

// int rowWithMax1s(vector<vector<int>> & arr){
//     int ans = -1, maxOnescnt = 0;
//     int n = arr.size();
//     int m = arr[0].size();

//     for(int row=0;row<n;row++){
//         int onesCnt = 0;

//         for(int col=0;col<m;col++){
//             if(arr[row][col] == 1)
//             onesCnt++;
//         }
//         if(onesCnt > maxOnescnt){
//             maxOnescnt = onesCnt; 
//             ans = row;
//         }
//     }
//     return ans;
// }

//binary search

int firstOne(vector<int> &row)
{
    int low = 0;
    int high = row.size() - 1;

    int ans = row.size();

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (row[mid] == 1)
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

int rowWithMax1s(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int maxOnes = 0;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int first = firstOne(arr[i]);

        int ones = m - first;

        if (ones > maxOnes)
        {
            maxOnes = ones;
            ans = i;
        }
    }

    return ans;
}


int main() {
    vector<vector<int>> arr = {{0,1,1,1},
        {0,0,1,1},
        {1,1,1,1},
        {0,0,0,0}};

    cout << "Row with Max 1s = " << rowWithMax1s(arr);
    return 0;
}