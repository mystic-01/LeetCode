class Solution {
public:
    // int countPaths(int i, int j, vector<vector<int>> &dp) {
    //     if (i == 0 && j == 0) return 1;
    //     if (i < 0 || j < 0) return 0;
    //     if (dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = countPaths(i - 1, j, dp) + countPaths(i, j - 1, dp);
    // };
    
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        // dp[0] = 1;
        for (auto i = 1; i < m; i++) {
            vector<int> curr(n, 0); 
            for (auto j = 0; j < n; j++) {
                if (i > 0) curr[j] += dp[j];       
                if (j > 0) curr[j] += curr[j - 1];
            };
            dp = curr;
        };
        return dp[n - 1];
    };
};
