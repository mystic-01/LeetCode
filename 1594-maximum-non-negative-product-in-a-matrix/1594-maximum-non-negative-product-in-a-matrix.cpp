static int mod = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<pair<long, long>>> minMaxGrid(row, vector<pair<long, long>>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                long curr = 1LL * grid[i][j];
                long firstLeft = j > 0 ? (minMaxGrid[i][j - 1].first * curr) : 0;
                long firstTop = i > 0 ? (minMaxGrid[i - 1][j].first * curr) : 0;
                long secondLeft = j > 0 ? (minMaxGrid[i][j - 1].second * curr) : 0;
                long secondTop = i > 0 ? (minMaxGrid[i - 1][j].second * curr) : 0;
        
                if (j >= 1 && i >= 1) {
                    minMaxGrid[i][j] = {max({firstLeft, firstTop, secondLeft, secondTop}), min({firstLeft, firstTop, secondLeft, secondTop})};
                } else if (j >= 1) {
                    minMaxGrid[i][j] = {max({firstLeft, secondLeft}), min({firstLeft, secondLeft})};
                } else if (i >= 1) {
                    minMaxGrid[i][j] = {max({firstTop, secondTop}), min({firstTop, secondTop})};
                } else {
                    minMaxGrid[i][j] = {curr, curr};                    
                };
            };        
        };
        return max(minMaxGrid[row - 1][col - 1].first, long(-1)) % mod;
    };
};