class Solution {
public:

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (auto i = m - 1; i >= 0; i--) {
            for (auto j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = min(dungeon[i][j], 0);                
                } else if (j == n - 1) {
                    dp[i][j] = min(dp[i + 1][j] + dungeon[i][j], 0);
                } else if (i == m - 1) {
                    dp[i][j] = min(dp[i][j + 1] + dungeon[i][j], 0);
                } else {
                    dp[i][j] = min(max(dp[i + 1][j], dp[i][j + 1]) + dungeon[i][j], 0);
                };
            };
        };
        return dp[0][0] >= 0 ? 1 : abs(dp[0][0]) + 1;
    };
};














