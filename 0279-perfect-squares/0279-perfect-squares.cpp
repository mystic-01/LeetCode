static const int outOfBound = 1e5;
class Solution {
public:
    int numSquares(int n) {
        int sqSize = sqrt(n) + 1;
        vector<vector<int>> dp(sqSize + 1, vector<int>(n + 1, outOfBound));
        dp[sqSize][0] = 0;
        
        for (int idx = sqSize - 1; idx >= 1; --idx) {
            for (int target = 0; target <= n; ++target) {
                int newTarget = target - (idx * idx);
                if (newTarget >= 0) {
                    dp[idx][target] = 1 + dp[idx][newTarget];
                };
                dp[idx][target] = min(dp[idx][target], dp[idx + 1][target]);
            };        
        };
        return dp[1][n];
    };
};