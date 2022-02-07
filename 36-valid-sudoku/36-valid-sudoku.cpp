class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        vector<int> col, row, box;
        for (int i = 0; i < 9; i++) {
            col = vector<int>(10);
            row = vector<int>(10);
            box = vector<int>(10);
            for (int j = 0; j < 9; j++){
                int ix = 3 * (i / 3) + (j / 3), jx = 3 * (i % 3) + (j % 3); 
                if ((board[i][j] != '.' && ++row[board[i][j] - '0'] > 1) ||
                    (board[j][i] != '.' && ++col[board[j][i] - '0'] > 1) ||
                    (board[ix][jx] != '.' && ++box[board[ix][jx] - '0'] > 1)) return false;
            };
        };
        return true;
    };
};
