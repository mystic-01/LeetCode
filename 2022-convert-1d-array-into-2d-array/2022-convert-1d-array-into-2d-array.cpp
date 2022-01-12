class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        
        if (original.size() != (m * n))  return {};
        int index = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = original[index++];
        return ans;
    };
};