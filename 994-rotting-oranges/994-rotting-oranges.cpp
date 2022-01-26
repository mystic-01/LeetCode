class Solution {
public:
    int changeOrange(int value, int &flag) {
        if (value == 1) {
            flag = 1;
            return 2;
        } else {
            return value;
        }
    };
    
    int orangesRotting(vector<vector<int>>& grid) {
        int flag = 1, count = -1, n = grid.size(), m = grid[0].size();
        while (flag) {
            flag = 0;
            count++;
            vector<vector<int>> newGrid(grid);
            for (auto i = 0; i < n; i++) {
                for (auto j = 0; j < m; j++) {
                    if (grid[i][j] == 2) {
                        if (i > 0) newGrid[i - 1][j] = changeOrange(grid[i - 1][j], flag); 
                        if (j > 0) newGrid[i][j - 1] = changeOrange(grid[i][j - 1], flag); 
                        if (i < n - 1) newGrid[i + 1][j] = changeOrange(grid[i + 1][j], flag); 
                        if (j < m - 1) newGrid[i][j + 1] = changeOrange(grid[i][j + 1], flag); 
                    };
                };            
            };
            swap(newGrid, grid);
        };
        for (auto i = 0; i < n; i++)
            for (auto j = 0; j < m; j++)
                if(grid[i][j] == 1) return -1;
        return count;
    };
};