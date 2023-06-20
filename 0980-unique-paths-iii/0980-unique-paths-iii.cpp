class Solution {
private:
    int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};    
public:
    int recurse(int i, int j, int &row, int &col, int &validCells, vector<vector<int>>& grid, set<pair<int, int>>& visited) {
        if (i >= row || i < 0 || j >= col || j < 0 || grid[i][j] == -1) return 0;        
        if (grid[i][j] == 2) return visited.size() == validCells;
        
        int ans = 0;
        
        for (auto k = 0; k < 4; k++) {
            int x = i + offsets[k][0], y = j + offsets[k][1];        
            if (!visited.count({x, y})) {
                visited.insert({x, y});
                ans += recurse(x, y, row, col, validCells, grid, visited);
                visited.erase({x, y});                
            };
        };
        
        return ans;
    };
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), validCells = 0, startX, startY;
        
        set<pair<int, int>> visited;
        
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                if (grid[i][j] == 1) startX = i, startY = j; 
                if (grid[i][j] != -1) validCells++;
            };        
        };
        
        visited.insert({startX, startY});
        return recurse(startX, startY, row, col, validCells, grid, visited);
    };
};