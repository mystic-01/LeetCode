static const int outOfBounds = -1e5, mod = 1e9 + 7;
static const pair<int, int> invalidPair = {-1, -1};
class Solution {
public:
    pair<int, int> recurse(int i, int j, vector<string> &board, pair<int, int> (*dp)[101]) {
        if (i == 0 && j == 0) {
            return {0, 1};            
        };        
        if (dp[i][j] != invalidPair) {
            return dp[i][j];    
        };
        pair<int, int> up = {outOfBounds, 0}, left = {outOfBounds, 0}, upLeft = {outOfBounds, 0};
        if (i > 0 && board[i - 1][j] != 'X') {
            up = recurse(i - 1, j, board, dp);
        };
        if (j > 0 && board[i][j - 1] != 'X') {
            left = recurse(i, j - 1, board, dp);
        };
        if (i > 0 && j > 0 && board[i - 1][j - 1] != 'X') {
            upLeft = recurse(i - 1, j - 1, board, dp);
        };
        
        int val = board[i][j] - '0';
        int maxVal = max({up.first, left.first, upLeft.first});
        int maxCount = 0;
        maxCount = (maxCount + (up.first == maxVal ? up.second : 0)) % mod;
        maxCount = (maxCount + (left.first == maxVal ? left.second : 0)) % mod;
        maxCount = (maxCount + (upLeft.first == maxVal ? upLeft.second : 0)) % mod;
        return dp[i][j] = {maxVal + val, maxCount};
    };
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int row = board.size(), col = board[0].size();
        board[row - 1][col - 1] = '0';
        pair<int, int> dp[101][101];
        for (int i = 0; i < 101; ++i) {
            for (int j = 0; j < 101; ++j) {
                dp[i][j] = {-1, -1};
            };        
        };
        pair<int, int> ans = recurse(row - 1, col - 1, board, dp);
        return {max(0, ans.first), ans.second};
    };
};