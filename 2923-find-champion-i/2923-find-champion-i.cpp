class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) grid[j].push_back(-1);
            };
        };
        for (int i = 0; i < n; ++i) {
            if (grid[i].back() != -1) return i;
        };
        return -1;
    };
};