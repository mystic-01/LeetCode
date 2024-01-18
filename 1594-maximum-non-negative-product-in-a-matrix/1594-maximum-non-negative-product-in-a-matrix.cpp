static int mod = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<pair<long, long>>> minMaxGrid(row, vector<pair<long, long>>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j >= 1 && i >= 1) {
                    long firstLeft = (minMaxGrid[i][j - 1].first * 1LL * grid[i][j]);
                    long firstTop = (minMaxGrid[i - 1][j].first * 1LL * grid[i][j]);
                    long secondLeft = (minMaxGrid[i][j - 1].second * 1LL * grid[i][j]);
                    long secondTop = (minMaxGrid[i - 1][j].second * 1LL * grid[i][j]);
                    minMaxGrid[i][j] = {max({firstLeft, firstTop, secondLeft, secondTop}), min({firstLeft, firstTop, secondLeft, secondTop})};
                } else if (j >= 1) {
                    long firstLeft = (minMaxGrid[i][j - 1].first * 1LL * grid[i][j]);
                    long secondLeft = (minMaxGrid[i][j - 1].second * 1LL * grid[i][j]);
                    minMaxGrid[i][j] = {max({firstLeft, secondLeft}), min({firstLeft, secondLeft})};
                } else if (i >= 1) {
                    long firstTop = (minMaxGrid[i - 1][j].first * 1LL * grid[i][j]);
                    long secondTop = (minMaxGrid[i - 1][j].second * 1LL * grid[i][j]);
                    minMaxGrid[i][j] = {max({firstTop, secondTop}), min({firstTop, secondTop})};
                } else {
                    minMaxGrid[i][j] = {1LL * grid[i][j], 1LL * grid[i][j]};                    
                };
            };        
        };
        return max(minMaxGrid[row - 1][col - 1].first, long(-1)) % mod;
    };
};