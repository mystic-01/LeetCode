class Solution {
public:
    int recurse(int i, int j, int &m, int &n, vector<vector<int>> &grid, int (*dp)[102]) {
        if (i > m || j > n) return dp[i][j] = 0;
        if (i < m && j < n && grid[i][j] == 1) return dp[i][j] = 0;
        if (i == m - 1 && j == n - 1) return dp[i][j] = 1;

        if (dp[i][j] != -1) return dp[i][j]; 
        
        int right = recurse(i + 1, j, m, n, grid, dp);
        int down = recurse(i, j + 1, m, n, grid, dp);

        return dp[i][j] = right + down;
    };
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), dp[102][102];
        
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                dp[i][j] = -1;
            };
        };
        
        return recurse(0, 0, m, n, grid, dp);
    };
};