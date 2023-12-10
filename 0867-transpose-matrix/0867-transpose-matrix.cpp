class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(row));
        int x = 0, y = 0;
        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row; ++i) {
                ans[x][y++] = matrix[i][j];
                if (y == row) x++, y = 0;
            };        
        };        
        return ans;
    };
};