class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size(), col = land[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (land[i][j]) {
                    vector<int> curr = {i, j, 0, 0};
                    for (int k = i; k < row && land[k][j]; ++k) {
                        for (int l = j; l < col && land[k][l]; ++l) {
                            land[k][l] = 0;
                            curr[2] = max(curr[2], k);
                            curr[3] = max(curr[3], l);
                        };                    
                    };
                    ans.push_back(curr);
                };
            };
        };
        return ans;
    };
};