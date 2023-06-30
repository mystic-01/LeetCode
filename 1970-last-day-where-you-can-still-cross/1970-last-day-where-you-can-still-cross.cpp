class Solution {
public:
    bool bfsCanReachEnd(int &row, int &col, int &size, vector<vector<int>> &cells) {
        int grid[row][col];
        int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                grid[i][j] = 0;
            };
        };
        
        for (int i = 0; i <= size; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        };
        
        queue<pair<int, int>> q;
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                grid[0][j] = 1;
            };
        };
        
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;            
            q.pop();
            
            if (x == row - 1) return true;
                
            for (int k = 0; k < 4; k++) {
                int a = x + offsets[k][0], b = y + offsets[k][1];    
                if (a >= 0 && a < row && b >= 0 && b < col && grid[a][b] == 0) {
                    q.push({a, b});
                    grid[a][b] = 1;        
                };
            };
        };
        return false;
    };
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0, hi = cells.size() - 1, ans = 0;
        
        
        while (lo <= hi) {            
            int mid = lo + (hi - lo) / 2;
            bool canReachEnd = bfsCanReachEnd(row, col, mid, cells);
            if (canReachEnd) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        };
        
        return ans + 1;
        // return ans == 0 ? 0 : ans + 1;
    };
};

/*

take grid, all equals 0
take cells, mark all waters, remove last 'row' water cells

bfs
if reached last row -> cool
else remove last cell and bfs

*/