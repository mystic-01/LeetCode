class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        
        int m = mat.size(), n = mat[0].size(), a = 0, b = 0;
        if (m * n != r * c) return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        
        for (auto i = 0; i < r; i++)
            for (auto j = 0; j < c; j++) {
                ans[i][j] = mat[a][b++];
                if (b == n) {
                    a = a + 1;
                    b = 0;
                };
            };
        return ans;
    };
};