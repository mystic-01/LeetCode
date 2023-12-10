class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        bool indegree[n];
        fill(indegree, indegree + n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) indegree[j] = 1;
            };
        };
        for (int i = 0; i < n; ++i) {
            if (!indegree[i]) return i;
        };
        return -1;
    };
};