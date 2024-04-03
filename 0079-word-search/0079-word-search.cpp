static const int offsets[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
public:
    bool recurse(int idx, int a, int b, vector<vector<char>>& board, string &word) {
        if (idx == word.size()) {
            return true;            
        };
        
        for (int k = 0; k < 4; ++k) {
            int i = offsets[k][0], j = offsets[k][1];
            if (i + a >= 0 && i + a < board.size() && j + b >= 0 && j + b < board[0].size()) {
                if (!(i == 0 && j == 0) && board[i + a][j + b] == word[idx]) {
                    char ch = board[i + a][j + b];
                    board[i + a][j + b] = ' ';
                    if (recurse(idx + 1, i + a, j + b, board, word)) {
                        return true;    
                    };                                                    
                    board[i + a][j + b] = ch;
                };    
            };
        };        
        return false;
    };
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    char ch = board[i][j];
                    board[i][j] = ' ';
                    if (recurse(1, i, j, board, word)) {
                        return true;    
                    };                       
                    board[i][j] = ch;
                };
            };
        };
        return false;
    };
};