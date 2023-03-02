class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for (auto i = 0; i < n; i++) sum = sum + mat[i][i] + mat[i][n - i - 1];
        return sum - (n % 2 ? mat[n / 2][n / 2] : 0);
    };
};