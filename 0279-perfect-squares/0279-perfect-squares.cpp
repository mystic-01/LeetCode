static const int outOfBound = 1e5;
class Solution {
public:
    int numSquares(int n) {
        int sqSize = sqrt(n) + 1;
        vector<vector<int>> dp(sqSize + 1, vector<int>(n + 1, outOfBound));
        dp[sqSize][0] = 0;
        
        for (int idx = sqSize - 1; idx >= 1; --idx) {
            for (int target = 0; target <= n; ++target) {
                int take = outOfBound, notTake = outOfBound, newTarget = target - (idx * idx);
                if (newTarget >= 0) {
                    take = 1 + dp[idx][newTarget];
                };
                notTake = dp[idx + 1][target];
                dp[idx][target] = min(take, notTake);                
            };        
        };
        return dp[1][n];
    };
};