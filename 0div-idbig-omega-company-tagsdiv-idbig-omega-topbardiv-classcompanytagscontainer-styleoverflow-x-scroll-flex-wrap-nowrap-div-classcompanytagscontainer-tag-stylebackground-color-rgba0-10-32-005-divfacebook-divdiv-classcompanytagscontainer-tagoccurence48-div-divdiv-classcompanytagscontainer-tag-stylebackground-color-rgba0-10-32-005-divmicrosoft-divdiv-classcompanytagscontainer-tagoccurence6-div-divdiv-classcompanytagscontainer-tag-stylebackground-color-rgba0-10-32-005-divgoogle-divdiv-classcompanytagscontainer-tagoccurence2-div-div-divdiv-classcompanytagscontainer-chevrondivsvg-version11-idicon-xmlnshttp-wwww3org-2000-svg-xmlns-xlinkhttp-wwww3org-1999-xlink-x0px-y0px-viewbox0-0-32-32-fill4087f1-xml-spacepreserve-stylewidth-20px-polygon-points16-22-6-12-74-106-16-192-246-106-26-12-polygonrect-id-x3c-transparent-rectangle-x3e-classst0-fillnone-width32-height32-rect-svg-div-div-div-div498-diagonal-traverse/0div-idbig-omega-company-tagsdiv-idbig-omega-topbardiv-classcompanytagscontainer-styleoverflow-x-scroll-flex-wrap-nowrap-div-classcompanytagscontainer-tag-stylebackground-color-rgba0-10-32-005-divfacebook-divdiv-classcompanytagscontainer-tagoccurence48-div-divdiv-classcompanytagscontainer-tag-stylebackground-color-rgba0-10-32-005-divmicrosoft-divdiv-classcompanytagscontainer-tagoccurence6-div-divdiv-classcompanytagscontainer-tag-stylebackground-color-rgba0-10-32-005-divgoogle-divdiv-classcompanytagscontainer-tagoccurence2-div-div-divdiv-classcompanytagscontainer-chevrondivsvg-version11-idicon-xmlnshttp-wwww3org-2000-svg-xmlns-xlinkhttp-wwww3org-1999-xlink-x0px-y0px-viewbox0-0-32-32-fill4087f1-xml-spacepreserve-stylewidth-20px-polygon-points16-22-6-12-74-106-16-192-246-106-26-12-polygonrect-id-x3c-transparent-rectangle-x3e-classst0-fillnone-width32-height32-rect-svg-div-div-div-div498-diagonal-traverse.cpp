class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), maxVal = row + col - 1, valPushed = 0;
        vector<int> ans;
        for (int i = 0; i < row; ++i) {
            vector<int> curr;
            for (int j = i, k = 0; j >= 0 && k < col; --j, ++k) {
                curr.push_back(mat[j][k]);
            };   
            if (i % 2 == 1) reverse(curr.begin(), curr.end());    
            for (int &x : curr) ans.push_back(x);
        };
        
        for (int i = 1; i < col; ++i) {
            vector<int> curr;
            for (int j = row - 1, k = i; j >= 0 && k < col; --j, ++k) {
                curr.push_back(mat[j][k]);
            };        
            if ((row - 1 + i) % 2 == 1) reverse(curr.begin(), curr.end());    
            for (int &x : curr) ans.push_back(x);
        };
        return ans;
    };
};