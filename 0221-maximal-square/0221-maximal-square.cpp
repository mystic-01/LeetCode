class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), maxVal = 0, prev[col], dp[col];
        memset(dp, 0, sizeof(dp));
        memset(prev, 0, sizeof(prev));
        for (int j = 0; j < col; ++j) {
            prev[j] = matrix[0][j] == '0' ? 0 : 1;
            maxVal = max(maxVal, prev[j]);
        };
        
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    dp[j] = 0;
                } else {
                    if (j != 0) {
                        // cout << prev[j - 1] << " " << prev[j] << " " << dp[j - 1] << "\n";
                        dp[j] = 1 + min({prev[j - 1], prev[j], dp[j - 1]});
                    } else {
                        dp[j] = 1;
                    };
                };
                maxVal = max(maxVal, dp[j]);
            };        
            for (int j = 0; j < col; ++j) {
                prev[j] = dp[j];
            };
        };
        return maxVal * maxVal;
    };
};