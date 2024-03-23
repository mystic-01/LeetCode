static const int mod = 1e9 + 7;

class Solution {
public:
    // Understand and learn the Power Exponentiation log(n) solution for this problem
    int checkRecord(int n) {
        int dp[2][3], prev[2][3];
        memset(dp, 0, sizeof(dp));
        memset(prev, 0, sizeof(prev));

        for (int aLeft = 0; aLeft <= 1; ++aLeft) {
            for (int l = 2; l >= 0; --l) {
                prev[aLeft][l] = 1;
            };
        };
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int aLeft = 0; aLeft <= 1; ++aLeft) {
                for (int l = 2; l >= 0; --l) {
                    int take = prev[aLeft][0];
                    if (aLeft) {
                        take = (take + (long long)prev[0][0]) % mod;
                    };
                    if (l < 2) {
                        take = (take + (long long)prev[aLeft][l + 1]) % mod;
                    };
                    dp[aLeft][l] = take;
                };
            };
            for (int aLeft = 0; aLeft <= 1; ++aLeft) {
                for (int l = 2; l >= 0; --l) {
                    prev[aLeft][l] = dp[aLeft][l];
                };
            };            
        };
        
        return prev[1][0];
    };
};