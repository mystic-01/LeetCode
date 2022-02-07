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