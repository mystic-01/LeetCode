class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int sum = 0, n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += (i == j || i + j == n - 1) ? mat[i][j] : 0;
            };
        };
        return sum;
    };
};