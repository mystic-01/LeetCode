class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int captures = 0., n = board.size();
        int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (board[i][j] == 'R') {
                    for (auto k = 0; k < 4; k++) {
                        int a = i + offset[k][0], b = j + offset[k][1];
                        while (a < n && a >= 0 && b >= 0 && b < n && board[a][b] != 'B') {
                            if (board[a][b] == 'p') {
                                captures++;
                                break;
                            };
                            a += offset[k][0];
                            b += offset[k][1];
                        };                    
                    };
                    return captures;
                };                                                        
            };
        };
        
        return captures;
    };
};