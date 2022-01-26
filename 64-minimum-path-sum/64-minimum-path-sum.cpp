class Solution {
public:
    int countPathSum(int i, int j, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (i > m || j > n) return 961;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == m && j == n) return dp[i][j] = grid[m][n];
        return dp[i][j] = min(countPathSum(i + 1, j, m, n, dp, grid), countPathSum(i, j + 1, m, n, dp, grid)) + grid[i][j];
    };
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() - 1, n = grid[0].size() - 1, count = 0;
                                          
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, - 1));
        return countPathSum(0, 0, m, n, dp, grid);
    };
};