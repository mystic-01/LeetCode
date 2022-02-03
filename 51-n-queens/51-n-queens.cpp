class Solution {
public:
    void recurseNQueens (int col, int n, vector<string> board, vector<vector<string>> & ans, 
    unordered_map<int, int> mRow, unordered_map<int, int> mUpperDiagonal, unordered_map<int, int> mLowerDiagonal) {
        if (col == n) {
            ans.push_back(board);
            return;                        
        };        
        
        for (auto row = 0; row < n; row++) {
            if (!mRow[row] && !mUpperDiagonal[col - row] && !mLowerDiagonal[col + row]) {
                board[row][col] = 'Q';
                mRow[row]++;
                mUpperDiagonal[col - row]++;
                mLowerDiagonal[col + row]++;
                recurseNQueens(col + 1, n, board, ans, mRow, mUpperDiagonal, mLowerDiagonal);
                board[row][col] = '.';
                mRow[row]--;
                mUpperDiagonal[col - row]--;
                mLowerDiagonal[col + row]--;                
            };            
        };
    };
    
    vector<vector<string>> solveNQueens(int n) {
        unordered_map<int, int> mRow, mUpperDiagonal, mLowerDiagonal;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        recurseNQueens (0, n, board, ans, mRow, mUpperDiagonal, mLowerDiagonal);
        return ans;
    };
};