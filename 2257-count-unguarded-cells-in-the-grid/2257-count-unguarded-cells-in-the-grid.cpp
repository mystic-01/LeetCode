class Solution {
public:
    int countUnguarded(int row, int col, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid[row][col], wSize = walls.size(), gSize = guards.size(); 
        int offsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int unguarded = row * col - wSize - gSize;
        
        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                grid[i][j] = 0;        
            };
        };
        
        for (auto it = 0; it < wSize; it++) {
            grid[walls[it][0]][walls[it][1]] = 2;
        }; 
        
        for (auto it = 0; it < gSize; it++) {
            grid[guards[it][0]][guards[it][1]] = 2;
        }; 
        
        for (auto it = 0; it < gSize; it++) {
            int x = guards[it][0], y = guards[it][1];
            
            for (auto k = 0; k < 4; k++) {
                int a = x + offsets[k][0], b = y + offsets[k][1];
                while (a < row && a >= 0 && b < col && b >= 0) {
                    if (grid[a][b] == 2) break;
                    else if (grid[a][b] == 0) grid[a][b] = 1, unguarded--;
                    a += offsets[k][0], b += offsets[k][1];
                };    
            };
        };
        
        return unguarded;
    };

};