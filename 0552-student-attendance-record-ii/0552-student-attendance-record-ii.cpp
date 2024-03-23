static const int mod = 1e9 + 7;

class Solution {
public:
    int checkRecord(int n) {
        int dp[n + 1][2][3];
        memset(dp, 0, sizeof(dp));

        for (int aLeft = 0; aLeft <= 1; ++aLeft) {
            for (int l = 2; l >= 0; --l) {
                dp[n][aLeft][l] = 1;
            };
        };
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int aLeft = 0; aLeft <= 1; ++aLeft) {
                for (int l = 2; l >= 0; --l) {
                    int take = dp[idx + 1][aLeft][0];
                    if (aLeft) {
                        take = (take + (long long)dp[idx + 1][0][0]) % mod;
                    };
                    if (l < 2) {
                        take = (take + (long long)dp[idx + 1][aLeft][l + 1]) % mod;
                    };
                    dp[idx][aLeft][l] = take;
                };
            };
        };
        
        return dp[0][1][0];
    };
};