class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size(), col = land[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (land[i][j] && (i == 0 || land[i - 1][j] == 0) && (j == 0 || land[i][j - 1] == 0)) {
                    vector<int> curr = {i, j, 0, 0};
                    int k = i;
                    while (k < row && land[k][j] == 1) {
                        ++k;    
                    };
                    curr[2] = --k;
                    while (j < col && land[i][j] == 1) {
                        ++j;    
                    };
                    curr[3] = --j;
                    ans.push_back(curr);
                };
            };
        };
        return ans;
    };
};