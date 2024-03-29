class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n;
        
        int dp[n + 1], ans = 1;
        dp[0] = 0, dp[1] = 1;
        
        for (int i = 2; i < n + 1; i++) {
            if ((i & 1) == 0) dp[i] = dp[i / 2];
            else dp[i] = dp[(i - 1) / 2] + dp[(i + 1) / 2];
            ans = max(ans, dp[i]);
        };
        return ans;
    };
};