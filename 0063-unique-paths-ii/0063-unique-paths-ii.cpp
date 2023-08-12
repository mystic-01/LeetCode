class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>>& obst) {
        if (i >= (m) || j >= (n)) return 0;
        if (obst[i][j] == 1) return 0;
        if (i == (m-1) && j == (n-1)) return 1;
        if (dp[i][j] !=-1) return dp[i][j];
        return dp[i][j] = countPaths(i + 1, j, m, n, dp, obst) + countPaths(i, j + 1, m, n, dp, obst);
    };
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        int nums = countPaths(0, 0, m, n, dp, obstacleGrid);
        return obstacleGrid[0][0] == 1 || m * n == 1 ? nums : dp[0][0];
    };
};