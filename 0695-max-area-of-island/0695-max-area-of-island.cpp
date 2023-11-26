class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxArea = 0, offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    q.push({i, j});  
                    grid[i][j] = 0;
                    int count = 0;
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        ++count;
                        for (int k = 0; k < 4; ++k) {
                            int a = x + offsets[k][0], b = y + offsets[k][1];
                            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b]) {
                                q.push({a, b});  
                                grid[a][b] = 0;
                            };    
                        };
                    };
                    maxArea = max(maxArea, count);
                };
            };            
        };
        return maxArea;
    };
};