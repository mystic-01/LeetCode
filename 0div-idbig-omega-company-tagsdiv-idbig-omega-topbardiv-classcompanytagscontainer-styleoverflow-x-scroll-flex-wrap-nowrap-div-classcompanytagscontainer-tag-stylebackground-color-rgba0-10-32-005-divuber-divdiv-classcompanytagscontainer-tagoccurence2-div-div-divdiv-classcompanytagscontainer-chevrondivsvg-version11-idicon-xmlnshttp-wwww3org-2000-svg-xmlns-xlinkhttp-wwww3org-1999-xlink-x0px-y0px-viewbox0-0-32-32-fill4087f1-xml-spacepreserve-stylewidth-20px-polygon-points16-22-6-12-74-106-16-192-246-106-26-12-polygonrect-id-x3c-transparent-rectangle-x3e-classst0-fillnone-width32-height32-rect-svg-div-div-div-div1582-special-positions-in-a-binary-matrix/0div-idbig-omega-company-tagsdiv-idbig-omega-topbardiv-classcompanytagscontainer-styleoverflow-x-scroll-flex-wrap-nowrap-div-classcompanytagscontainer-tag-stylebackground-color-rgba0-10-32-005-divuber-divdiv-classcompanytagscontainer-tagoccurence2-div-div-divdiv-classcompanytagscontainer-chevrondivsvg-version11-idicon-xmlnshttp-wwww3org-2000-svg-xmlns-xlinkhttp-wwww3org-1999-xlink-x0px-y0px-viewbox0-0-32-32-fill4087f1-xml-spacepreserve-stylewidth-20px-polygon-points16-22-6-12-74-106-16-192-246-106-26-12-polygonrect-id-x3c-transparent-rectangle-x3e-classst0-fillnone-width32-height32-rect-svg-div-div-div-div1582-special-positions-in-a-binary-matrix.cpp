class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), special = 0;
        int rowVec[row], colVec[col];
        fill(rowVec, rowVec + row, 0);
        fill(colVec, colVec + col, 0);
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j]) ++rowVec[i], ++colVec[j];
            };            
        };        
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] && rowVec[i] == 1 && colVec[j] == 1) ++special;
            };            
        };
        return special;
    };
};