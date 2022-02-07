// class Solution {
// public:
    
//     void nQueens(int col, int n, vector<vector<string>>& ans, vector<string> board, 
//     vector<int> mRow, vector<int> mUpperDiagonal, vector<int> mLowerDiagonal) {
//         if (col == n) {
//             ans.push_back(board); return; 
//         };
//         for (auto row = 0; row < n; row++) {
//             if (!mRow[row] && !mLowerDiagonal[col + row] && !mUpperDiagonal[n + col - row]) {
//                 board[row][col] = 'Q';
//                 mRow[row] = mLowerDiagonal[col + row] = mUpperDiagonal[n + col - row] = 1;
//                 nQueens(col + 1, n, ans, board, mRow, mUpperDiagonal, mLowerDiagonal);
//                 board[row][col] = '.';
//                 mRow[row] = mLowerDiagonal[col + row] = mUpperDiagonal[n + col - row] = 0;
//             };            
//         };
//     };

    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n, '.'));
//         vector<int> mRow(n, 0), mUpperDiagonal(2 * n, 0), mLowerDiagonal(2 * n, 0);
//         nQueens(0, n, ans, board, mRow, mUpperDiagonal, mLowerDiagonal);
//         return ans;
//     };
// };

class Solution {
public:
    
    void nQueens(int col, int n, vector<vector<string>>& ans, vector<string> board, vector<int> v) {
        if (col == n) {
            ans.push_back(board); return; 
        };
        for (auto row = 0; row < n; row++) {
            if (!v[row] && !v[n + col + row] && !v[4 * n + col - row]) {
                board[row][col] = 'Q';
                v[row] = v[n + col + row] = v[4 * n + col - row] = 1;
                nQueens(col + 1, n, ans, board, v);
                board[row][col] = '.';
                v[row] = v[n + col + row] = v[4 * n + col - row] = 0;
            };            
        };
    };

    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> v(5 * n, 0);
        nQueens(0, n, ans, board, v);
        return ans;
    };
};