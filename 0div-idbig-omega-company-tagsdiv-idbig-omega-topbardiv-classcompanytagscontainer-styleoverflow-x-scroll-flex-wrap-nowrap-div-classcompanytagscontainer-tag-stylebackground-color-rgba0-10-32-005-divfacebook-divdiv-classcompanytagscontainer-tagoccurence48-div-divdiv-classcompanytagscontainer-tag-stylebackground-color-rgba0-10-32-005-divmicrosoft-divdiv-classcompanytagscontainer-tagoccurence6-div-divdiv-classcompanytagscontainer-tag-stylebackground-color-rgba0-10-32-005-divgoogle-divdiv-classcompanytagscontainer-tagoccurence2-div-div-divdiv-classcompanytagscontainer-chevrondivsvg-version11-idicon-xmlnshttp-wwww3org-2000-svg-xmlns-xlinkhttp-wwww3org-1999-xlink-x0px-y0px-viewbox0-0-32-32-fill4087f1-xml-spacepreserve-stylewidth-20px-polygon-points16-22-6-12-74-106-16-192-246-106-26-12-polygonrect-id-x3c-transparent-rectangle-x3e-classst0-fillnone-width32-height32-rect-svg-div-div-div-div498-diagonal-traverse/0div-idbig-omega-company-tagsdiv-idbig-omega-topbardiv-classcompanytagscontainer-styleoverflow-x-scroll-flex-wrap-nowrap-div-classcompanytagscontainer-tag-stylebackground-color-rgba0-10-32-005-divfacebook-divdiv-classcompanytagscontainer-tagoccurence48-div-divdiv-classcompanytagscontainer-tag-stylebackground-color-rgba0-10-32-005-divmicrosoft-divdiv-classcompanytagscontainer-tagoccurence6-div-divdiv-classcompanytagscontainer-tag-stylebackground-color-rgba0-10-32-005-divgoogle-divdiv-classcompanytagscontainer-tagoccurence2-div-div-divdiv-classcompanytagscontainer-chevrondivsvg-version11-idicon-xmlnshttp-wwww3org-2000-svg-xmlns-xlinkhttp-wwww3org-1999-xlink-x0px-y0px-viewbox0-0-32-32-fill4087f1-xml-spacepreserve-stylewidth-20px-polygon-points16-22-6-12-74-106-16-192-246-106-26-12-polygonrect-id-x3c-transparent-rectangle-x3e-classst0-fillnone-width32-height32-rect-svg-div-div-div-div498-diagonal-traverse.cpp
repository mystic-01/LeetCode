class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), maxVal = row + col - 2;
        vector<int> ans;
        vector<vector<int>> temp(maxVal + 1);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                temp[i + j].push_back(mat[i][j]);
            };        
        };
        for (int i = 0; i < maxVal + 1; ++i) {
            if (i % 2) {
                for (auto it = temp[i].begin(); it != temp[i].end(); ++it) {
                    ans.push_back(*it);    
                };    
            } else {
                for (auto it = temp[i].rbegin(); it != temp[i].rend(); ++it) {
                    ans.push_back(*it);    
                };                
            };
        };
        
        return ans;
    };
};