class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        vector<int> col(n, 0), row(n, 0);
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[i] = max(col[i], grid[j][i]);
            };            
        };
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                ans += (min(row[i], col[j]) - grid[i][j]);
            };            
        };
        return ans;
    };
};