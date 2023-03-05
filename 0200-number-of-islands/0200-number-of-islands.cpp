class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                   
                    while (!q.empty()) {
                        int i = q.front().first, j = q.front().second;
                        q.pop();
                        if (i - 1 >= 0 && grid[i - 1][j] == '1') q.push({i - 1, j}), grid[i - 1][j] = '0';
                        if (i + 1 < m && grid[i + 1][j] == '1') q.push({i + 1, j}), grid[i + 1][j] = '0';
                        if (j - 1 >= 0 && grid[i][j - 1] == '1') q.push({i, j - 1}), grid[i][j - 1] = '0';
                        if (j + 1 < n && grid[i][j + 1] == '1') q.push({i, j + 1}), grid[i][j + 1] = '0';
                    };
                };
            };        
        };        
        return islands;
    };
};