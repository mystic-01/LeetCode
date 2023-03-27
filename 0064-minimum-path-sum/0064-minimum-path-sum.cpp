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

// class Solution {
// public:
//     int sumPaths(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//         if (i == 0 && j == 0) return grid[0][0];
//         if (i < 0 || j < 0) return INT_MAX;
//         if (dp[i][j] != -1) return dp[i][j];
//         return dp[i][j] = min(sumPaths(i - 1, j, grid, dp), sumPaths(i, j - 1, grid, dp)) + grid[i][j];
//     };                                          

    
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return sumPaths(m - 1, n  - 1, grid, dp);                                          
//     };
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        
        for (auto i = 0; i < m; i++) {
            vector<int> curr(n, 0);        
            for (auto j = 0; j < n; j++) {
                int top = INT_MAX, left = INT_MAX;
                
                if (i > 0) top = dp[j];
                if (j > 0) left = curr[j - 1];
                
                int ans = min(top, left);
                curr[j] = (ans == INT_MAX) ? grid[i][j] : ans + grid[i][j];
            }; 
            dp = curr;
        };            
        return dp[n  - 1];                                          
    };
};






