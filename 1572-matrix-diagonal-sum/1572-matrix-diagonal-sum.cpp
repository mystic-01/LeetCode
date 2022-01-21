class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int sum = 0, n = mat.size();
        for (int i = 0; i < n; i++)
            sum += mat[i][i] + mat[i][n - i - 1];
        return n % 2 ? sum - mat[n/2][n/2]: sum;
    };
};