class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != (m * n))  {
            vector<vector<int>> ans;
            return ans;
        }
        int index = 0;
        vector<vector<int>> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i].resize(n);
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[index];
                index++;
            };
        };
        return ans;
    };
};