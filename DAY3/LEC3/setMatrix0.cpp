#include <bits/stdc++.h>
using namespace std;

// void setRow(vector<vector<int>> & arr, int row){
//     for(int j=0;j< arr[0].size();j++){
//         arr[row][j]=-1;
//     }
// }

// void setCol(vector<vector<int>> & arr, int column){
//     for(int i=0;i< arr.size();i++){
//         arr[i][column]=-1;
//     }
// }

// void setMatrix0(vector<vector<int>> & arr, int n, int m){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j] == 0){
//             setRow(arr,i);
//             setCol(arr,j);
//         }
//     }
// }
//  for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){

//          if(arr[i][j] == -1){
//             arr[i][j]=0;
//         }
//     }
//   }
// }

//optimized

void setMatrix0(vector<vector<int>> &arr, int n, int m) {

    int col0 = 1;

    for(int i = 0; i < n; i++) {

        if(arr[i][0] == 0)
            col0 = 0;

        for(int j = 1; j < m; j++) {

            if(arr[i][j] == 0) {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {

            if(arr[i][0] == 0 || arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    if(arr[0][0] == 0) {
        for(int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }

    if(col0 == 0) {
        for(int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> arr = {
    {1,1,1},
    {1,0,1},
    {1,1,1}
};
    int n = arr.size();
    int m = arr[0].size();

    setMatrix0(arr,n,m);
     for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

        cout << arr[i][j]<< " ";
    }
    cout << endl;
}
    return 0;
}