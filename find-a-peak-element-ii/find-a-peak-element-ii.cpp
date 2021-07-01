class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans(2, 0);
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                int element = mat[i][j];
                if (j+1 == mat[0].size() || element > mat[i][j+1]) {
                    if (j-1 < 0 || element > mat[i][j-1]) {
                        if (i+1 == mat.size() || element > mat[i+1][j]) {
                            if (i-1 < 0 || element > mat[i-1][j]) {
                                ans[0] = i;
                                ans[1] = j;
                                return ans;
                            };
                        };
                    };
                };
            };
        };
        return ans;
    };
};