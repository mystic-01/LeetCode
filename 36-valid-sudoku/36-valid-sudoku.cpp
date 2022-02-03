class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        vector<int> col, row;
        for (int i = 0; i < 9; i++) {
            col = vector<int>(10);
            row = vector<int>(10);
            for (int j = 0; j < 9; j++)
                if ((board[i][j] != '.' && ++row[board[i][j] - '0'] > 1) ||
                    (board[j][i] != '.' && ++col[board[j][i] - '0'] > 1)) return false;
        };
        
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < 9; i++) {
                if (i % 3 == 0) col = vector<int>(10);
                for (int j = (3 * k); j  < 3 + (3 * k); j++) {
                    if (board[i][j] != '.' && ++col[board[i][j] - '0'] > 1) return false;
                };
            };
        };
        return true;
    };
};
