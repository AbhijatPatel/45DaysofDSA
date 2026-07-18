#include <bits/stdc++.h>
using namespace std;
//brute
// void rotateMatrixBy90(vector<vector<int>> &arr) {

//     int n = arr.size();

//     vector<vector<int>> ans(n, vector<int>(n));

//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             ans[j][n - 1 - i] = arr[i][j];
//         }
//     }
//     arr = ans;
// }

//optimized
void rotateMatrixBy90(vector<vector<int>> &arr) {
    int n = arr.size();

    //Transpose the matrix
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    //Reverse each row
    for(int i = 0; i < n; i++) {
        reverse(arr[i].begin(), arr[i].end());
    }
}

int main() {

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrixBy90(arr);

    cout << "Matrix after rotating 90 degrees clockwise:\n";

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
