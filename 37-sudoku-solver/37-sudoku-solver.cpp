class Solution {
public:
    
    bool isValid(char c, int row, int col, vector<vector<char>> board) {
        for (auto i = 0; i < 9; i++)
            if (board[row][i] == c || board[i][col] == c || 
                board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c) return 0;               
        return 1;
    };
    
    bool solve(vector<vector<char>> & board) {
        for (auto i = 0; i < 9; i++)  {
            for (auto j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (auto c = '1'; c <= '9'; c++)
                        if (isValid(c, i, j, board)) {
                            board[i][j] = c;
                            if (solve(board)) return 1;
                            board[i][j] = '.'; 
                        }; 
                    return 0;
                };              
            };        
        };
        return 1;
    };
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    };
};