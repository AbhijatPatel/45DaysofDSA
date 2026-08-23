#include <bits/stdc++.h>
using namespace std;
//better
    //     bool isSafe(vector<string>& board, int row, int col, int n) {

    //     // Check same column
    //     for (int i = 0; i < row; i++) {
    //         if (board[i][col] == 'Q') {
    //             return false;
    //         }
    //     }

    //     // Check upper-left diagonal
    //     for (int i = row - 1, j = col - 1;
    //          i >= 0 && j >= 0;
    //          i--, j--) {

    //         if (board[i][j] == 'Q') {
    //             return false;
    //         }
    //     }

    //     // Check upper-right diagonal
    //     for (int i = row - 1, j = col + 1;
    //          i >= 0 && j < n;
    //          i--, j++) {

    //         if (board[i][j] == 'Q') {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // void solve(int row, int n,
    //            vector<string>& board,
    //            vector<vector<string>>& ans) {

    //     // All rows completed
    //     if (row == n) {
    //         ans.push_back(board);
    //         return;
    //     }

    //     // Try every column
    //     for (int col = 0; col < n; col++) {

    //         if (isSafe(board, row, col, n)) {

    //             // Place queen
    //             board[row][col] = 'Q';

    //             // Move to next row
    //             solve(row + 1, n, board, ans);

    //             // Backtrack
    //             board[row][col] = '.';
    //         }
    //     }
    // }

    // vector<vector<string>> solveNQueens(int n) {

    //     vector<vector<string>> ans;

    //     vector<string> board(n,string(n, '.'));

    //     solve(0, n, board, ans);

    //     return ans;  
    // }
//optimized
    void solve(
        int row,
        int n,
        vector<string>& board,
        vector<int>& col,
        vector<int>& diag1,
        vector<int>& diag2,
        vector<vector<string>>& ans
    ) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            int d1 = row - c + n - 1;
            int d2 = row + c;

            // Check if column or diagonal is occupied
            if (col[c] || diag1[d1] || diag2[d2]) {
                continue;
            }

            // Place queen
            board[row][c] = 'Q';

            col[c] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;

            // Move to next row
            solve(
                row + 1,
                n,
                board,
                col,
                diag1,
                diag2,
                ans
            );

            // Backtrack
            board[row][c] = '.';

            col[c] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(
            n,
            string(n, '.')
        );

        vector<int> col(n, 0);

        vector<int> diag1(2 * n - 1, 0);

        vector<int> diag2(2 * n - 1, 0);

        solve(
            0,
            n,
            board,
            col,
            diag1,
            diag2,
            ans
        );

        return ans;
    }
    int main() {

    // Number of queens
    int n;

    cout << "Enter number of queens: ";
    cin >> n;


    // Get all solutions
    vector<vector<string>> ans = solveNQueens(n);


    // Print number of solutions
    cout << "\nTotal Solutions: "
         << ans.size()
         << "\n\n";


    // Print all solutions
    for (int i = 0; i < ans.size(); i++) {

        cout << "Solution " << i + 1 << ":\n";

        for (string row : ans[i]) {

            cout << row << endl;
        }

        cout << endl;
    }


    return 0;
}