class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), ans = 2147483647;        
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                matrix[i][j] += min({j - 1 >= 0 ? matrix[i - 1][j - 1] : 2147483647, matrix[i - 1][j], j + 1 < col ? matrix[i - 1][j + 1] : 2147483647});       
            };        
        };
        for (int j = 0; j < col; ++j) {
            ans = min(ans, matrix[row - 1][j]);
        };        
        return ans;
    };
};