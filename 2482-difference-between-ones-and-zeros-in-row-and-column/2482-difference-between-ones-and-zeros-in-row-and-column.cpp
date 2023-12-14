class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), oneRows[row], oneCols[col];
        fill(oneRows, oneRows + row, 0);
        fill(oneCols, oneCols + col, 0);
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                oneRows[i] += grid[i][j], oneCols[j] += grid[i][j];
            };        
            
        };
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                grid[i][j] = oneRows[i] + oneCols[j] - (row - oneRows[i] + col - oneCols[j]);
            };        
            
        };
        return grid;
    };
};