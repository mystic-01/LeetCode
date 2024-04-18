class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), perimeter = 0;        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    perimeter += (i - 1 < 0 || grid[i - 1][j] == 0);                        
                    perimeter += (j - 1 < 0 || grid[i][j - 1] == 0);                        
                    perimeter += (i + 1 >= row || grid[i + 1][j] == 0);                        
                    perimeter += (j + 1 >= col || grid[i][j + 1] == 0);                        
                };
            };        
        };
        return perimeter;
    };
};