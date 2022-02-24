class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0, time = 0, n = grid.size(), m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < m; j++) {
                if (grid[i][j] == 1) count++;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                };
            };
        };
        
        if (!count) return 0;
        
        while (!q.empty() && count) {
            int size = q.size();
            for (auto it = 0; it < size; it++) {
                int i = q.front().first, j = q.front().second;
                if (i + 1 < n && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2, count--;
                    q.push({i + 1, j});
                };
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2, count--;
                    q.push({i - 1, j});
                };
                if (j + 1 < m && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2, count--;
                    q.push({i, j + 1});
                };
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2, count--;
                    q.push({i, j - 1});
                };
                q.pop();
            };
            time++;
        };
        return (count) ? -1 : time;
    };
};