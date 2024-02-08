static const int outOfBound = 1e5;
class Solution {
public:
    int numSquares(int n) {
        int sqSize = sqrt(n) + 1, dp[n + 1];
        fill(dp, dp + n + 1, outOfBound);
        dp[0] = 0;
        
        for (int idx = sqSize - 1; idx >= 1; --idx) {
            int sq = idx * idx;
            for (int target = sq; target <= n; ++target) {
                dp[target] = min(dp[target], 1 + dp[target - sq]);
            };        
        };
        return dp[n];
    };
};