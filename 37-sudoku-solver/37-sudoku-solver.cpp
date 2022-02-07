class Solution {
public:
    bool isValid(char c, int row, int col, vector<vector<char>> board, int size) {
        int x = sqrt(size); 
        for (auto i = 0; i < size; i++) {
            if (board[row][i] == c) return 0;               
            if (board[i][col] == c) return 0;               
            if (board[x * (row / x) + (i / x)][x * (col / 3) + (i % x)] == c) return 0;               
        };
        return 1;
    };
    
    bool solve(vector<vector<char>> & board, int n) {
        for (auto i = 0; i < n; i++)  {
            for (auto j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    for (auto c = '1'; c <= '9'; c++) {
                        if (isValid(c, i, j, board, n)) {
                            board[i][j] = c;
                            if (solve(board, n)) return true;
                            board[i][j] = '.'; }; 
                    }; 
                    return false;
                };              
            };        
        };
        return true;
    };
    
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board, board.size());        
    };
};