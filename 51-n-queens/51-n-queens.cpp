class Solution {
public:
    
    void nQueens(int col, int n, vector<vector<string>>& ans, vector<string> board, 
    unordered_map<int, int> mRow, unordered_map<int, int> mUpperDiagonal, unordered_map<int, int> mLowerDiagonal) {
        if (col == n) {
            ans.push_back(board); return; 
        };
        for (auto row = 0; row < n; row++) {
            if (!mRow[row] && !mLowerDiagonal[col + row] && !mUpperDiagonal[col - row]) {
                board[row][col] = 'Q';
                mRow[row] = mLowerDiagonal[col + row] = mUpperDiagonal[col - row] = 1;
                nQueens(col + 1, n, ans, board, mRow, mUpperDiagonal, mLowerDiagonal);
                board[row][col] = '.';
                mRow[row] = mLowerDiagonal[col + row] = mUpperDiagonal[col - row] = 0;
            };            
        };
    };

    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        unordered_map<int, int> mRow, mUpperDiagonal, mLowerDiagonal;
        nQueens(0, n, ans, board, mRow, mUpperDiagonal, mLowerDiagonal);
        return ans;
    };
};