static const int oob = 1e9 + 1;
class Solution {
public:
    int recurse(int i, int j, int &n, vector<vector<int>> &grid, int (*dp)[201]) {
        // if (i == n - 1) {
        //     return dp[i][j] = grid[i][j];    
        // };
        // if (dp[i][j] != -1) {
        //     return dp[i][j];
        // };
        
        int ans = oob;
        for (int k = 0; k < n; ++k) {
            if (k != j) {
                ans = min(ans, grid[i][j] + recurse(i + 1, k, n, grid, dp));
            };            
        };
        return dp[i][j] = ans;
    };
    
    int minFallingPathSum(vector<vector<int>> &grid) {
        int n = grid.size(), ans = oob, dp[201][201];
        memset(dp, -1, sizeof(dp));
        
        for (int j = n - 1; j >= 0; --j) {
            dp[n - 1][j] = grid[n - 1][j];    
        };
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int ans = oob;
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        ans = min(ans, grid[i][j] + dp[i + 1][k]);
                    };            
                };
                dp[i][j] = ans;
            };        
        };
        
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[0][j]);
        };
        return ans;
    };
};


/*

[[-73, 61,43,-48,-36]
,[  3, 30,27, 57, 10]
,[ 96,-76,84, 59,-15]
,[  5,-49,76, 31, -7]
,[ 97, 91,61,-46, 67]]

*/