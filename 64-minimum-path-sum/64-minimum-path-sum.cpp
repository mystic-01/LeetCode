
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






