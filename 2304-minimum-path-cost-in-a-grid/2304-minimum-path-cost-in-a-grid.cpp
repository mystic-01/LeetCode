class Solution {
public:
    int recurse(int i, int j, int &row, int &col, vector<vector<int>>& grid, vector<vector<int>>& moveCost, int (*dp)[52]) {
        if (i == row - 1) return grid[i][j];
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 1e7;
        for (int k = 0; k < col; k++) {
            int curr = grid[i][j] + moveCost[grid[i][j]][k] + recurse(i + 1, k, row, col, grid, moveCost, dp);       
            ans = min(ans, curr);
        };        
        
        return dp[i][j] = ans;
    };
    
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int row = grid.size(),  col = grid[0].size(), ans = 1e7, dp[52][52];
        
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                dp[i][j] = -1;
            };
        };
        
        for (int j = 0; j < col; j++) {
            ans = min(ans, recurse(0, j, row, col, grid, moveCost, dp));
        };        
        
        // for (int i = 0; i < 52; i++) {
        //     for (int j = 0; j < 52; j++) {
        //         if (dp[i][j] != -1) cout << i << " " << j << " " << dp[i][j] << "\n";
        //     };
        // };        
        return ans;
    };
};