// class Solution {
// public:
//     int sumPaths(int i, int j, vector<vector<int>>& grid) {
//         if (i == 0 && j == 0) return grid[0][0];
//         if (i < 0 || j < 0) return INT_MAX;
        
//         return min(sumPaths(i - 1, j, grid), sumPaths(i, j - 1, grid)) + grid[i][j];
//     };                                          

    
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         return sumPaths(m - 1, n  - 1, grid);                                          
//     };
// };

class Solution {
public:
    int sumPaths(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min(sumPaths(i - 1, j, grid, dp), sumPaths(i, j - 1, grid, dp)) + grid[i][j];
    };                                          

    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return sumPaths(m - 1, n  - 1, grid, dp);                                          
    };
};






