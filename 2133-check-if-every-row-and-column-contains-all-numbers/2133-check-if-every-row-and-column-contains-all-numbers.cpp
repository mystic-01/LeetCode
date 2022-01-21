class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> row;
        for (auto i = 0; i < n; i++) {
            row = vector<int>(n, -1);
            for (auto j = 0; j < n; j++)
                row[matrix[i][j] - 1]++;
            if (find(row.begin(), row.end(), -1) != row.end()) return 0;
        };
        for (auto i = 0; i < n; i++) {
            row = vector<int>(n, -1);
            for (auto j = 0; j < n; j++)
                row[matrix[j][i] - 1]++;
            if (find(row.begin(), row.end(), -1) != row.end()) return 0;
        };
        return true;
    };
};