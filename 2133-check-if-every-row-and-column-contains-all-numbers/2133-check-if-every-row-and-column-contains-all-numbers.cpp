class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int n = matrix.size();
        vector<int> row, col;
        for (auto i = 0; i < n; i++) {
            row = col = vector<int>(n, -1);
            for (auto j = 0; j < n; j++) {
                row[matrix[i][j] - 1]++;
                col[matrix[j][i] - 1]++;
            };
            if (find(row.begin(), row.end(), -1) != row.end() || find(col.begin(), col.end(), -1) != col.end()) return 0;
        };
        return true;
    };
};