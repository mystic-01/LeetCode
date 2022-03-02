class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), perimeter = 0;
        int offsets[4] = {1, 0, -1, 0};
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited.insert({i, j});
                    while (!q.empty()) {
                        int size = q.size();
                        for (auto it = 0; it < size; it++) {
                            visited.insert({q.front().first, q.front().second});
                            
                            for (auto k = 0; k < 4; k++) {
                                int x = q.front().first + offsets[k];
                                int y = q.front().second + offsets[(k + 1) % 4];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                    if (!visited.count({x, y})) 
                                        q.push({x, y}), visited.insert({x, y});
                                } else perimeter++;
                            };
                            q.pop();
                        };
                    };
                    return perimeter;
                };
            };
        };
        return perimeter;
    };
};


