class Solution {
public:

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<int> dp(n, 0);
        
        for (auto i = m - 1; i >= 0; i--) {
            vector<int> curr(n, 0);        
            for (auto j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    curr[j] = min(dungeon[i][j], 0);                
                } else if (j == n - 1) {
                    curr[j] = min(dp[j] + dungeon[i][j], 0);
                } else if (i == m - 1) {
                    curr[j] = min(curr[j + 1] + dungeon[i][j], 0);
                } else {
                   curr[j] = min(max(dp[j], curr[j + 1]) + dungeon[i][j], 0);
                };
            };
            dp = curr;
        };
        return dp[0] >= 0 ? 1 : abs(dp[0]) + 1;
    };
};














