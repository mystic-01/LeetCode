class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size(), i = 0, indegree[n];
        fill(indegree, indegree + n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) ++indegree[j];
            };
        };
        for (int i = 0; i < n; ++i) {
            if (!indegree[i]) return i;
        };
        return -1;
    };
};