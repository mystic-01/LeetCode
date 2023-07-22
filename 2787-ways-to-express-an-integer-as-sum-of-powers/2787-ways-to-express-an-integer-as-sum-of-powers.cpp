int mod = 1e9 + 7, powers[301][6] = {0};

class Solution {
public:    
    int recurse(int idx, int value, int &x, int &target, int (*powers)[6], int(*dp)[301]) {
        if (value >= target) return value == target;
        int ans = 0;
    
        if (dp[idx][value] != -1) return dp[idx][value];
        
        for (int i = idx + 1; i <= target && value + powers[i][x] <= target; i++) {
            ans = (ans + recurse(i, value + powers[i][x], x, target, powers, dp)) % mod;
        };
        
        return dp[idx][value] = ans;
    };
    
    int numberOfWays(int target, int x) {
        int ans = 0, dp[301][301];
        
        for (int i = 1; i < 301; i++) {
            for (int j = 1; j < 301; j++) {
                dp[i][j] = -1;
            };        
        };

        if (powers[0][0] == 0) {
            for (int p = 1; p < 6; p++) {
                powers[0][p] = 1;
                for (int i = 1; i <= 300 && powers[i - 1][p] <= 300; i++) {
                    powers[i][p] = pow(i, p);     
                };
            };
        };
        
        for (int i = 1; i <= target && powers[i][x] <= target; i++) {
            ans = (ans + recurse(i, powers[i][x], x, target, powers, dp)) % mod;
        };
        
        return ans;
    };    
};