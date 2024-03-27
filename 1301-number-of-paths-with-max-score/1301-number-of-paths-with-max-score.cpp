static const int outOfBounds = -1e5, mod = 1e9 + 7;
static const pair<int, int> invalidPair = {-1, -1};

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int row = board.size(), col = board[0].size();
        board[row - 1][col - 1] = '0';
        pair<int, int> dp[col + 1], prev[col + 1];
        for (int j = 0; j < col + 1; ++j) {
            prev[j] = {-1, -1};
        };
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = {0, 1};            
                    continue;
                };        
                pair<int, int> up = {outOfBounds, 0}, left = {outOfBounds, 0}, upLeft = {outOfBounds, 0};
                if (i > 0 && board[i - 1][j] != 'X') {
                    up = prev[j];
                };
                if (j > 0 && board[i][j - 1] != 'X') {
                    left = dp[j - 1];
                };
                if (i > 0 && j > 0 && board[i - 1][j - 1] != 'X') {
                    upLeft = prev[j - 1];
                };

                int val = board[i][j] - '0';
                int maxCount = 0, maxVal = max({up.first, left.first, upLeft.first});
                maxCount = (maxCount + (up.first == maxVal ? up.second : 0)) % mod;
                maxCount = (maxCount + (left.first == maxVal ? left.second : 0)) % mod;
                maxCount = (maxCount + (upLeft.first == maxVal ? upLeft.second : 0)) % mod;
                dp[j] = {maxVal + val, maxCount};
            };        
            for (int j = 0; j < col + 1; ++j) {
                prev[j] = dp[j];
            };            
        };
        
        pair<int, int> ans = prev[col - 1];
        return {max(0, ans.first), ans.second};
    };
};