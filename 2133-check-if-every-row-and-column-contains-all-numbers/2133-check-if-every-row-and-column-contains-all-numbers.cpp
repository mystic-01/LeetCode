class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        int n = matrix.size();
        
        for (auto i = 0; i < n; i++) {
            row = unordered_set<int>(n);
            col = unordered_set<int>(n);
            for (auto j = 0; j < n; j++) {
                row.insert(matrix[i][j]);
                col.insert(matrix[j][i]);
            };
            if (row.size() != n || col.size() != n) return false;
        };
        return true;
    };
};