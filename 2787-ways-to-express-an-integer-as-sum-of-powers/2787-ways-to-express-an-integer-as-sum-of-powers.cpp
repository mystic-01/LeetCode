class Solution {
private:
    int mod = 1e9 + 7;
public:    
    int recurse(int idx, int value, int &target, int *powers, int(*dp)[301]) {
        if (value == target) return 1;
        int ans = 0;
    
        if (dp[idx][value] != -1) return dp[idx][value];
        
        for (int i = idx + 1; i <= target && value + powers[i] <= target; i++) {
            ans = (ans + recurse(i, value + powers[i], target, powers, dp)) % mod;
        };
        
        return dp[idx][value] = ans;
    };
    
    int numberOfWays(int target, int x) {
        int ans = 0,  powers[301] = {0}, dp[301][301];
        
        for (int i = 1; i < 301; i++) {
            for (int j = 1; j < 301; j++) {
                dp[i][j] = -1;
            };        
        };
        
        for (int i = 1; i <= target && powers[i - 1] <= target; i++) powers[i] = pow(i, x);
        
        for (int i = 1; i <= target && powers[i] <= target; i++) {
            ans = (ans + recurse(i, powers[i], target, powers, dp)) % mod;
        };
        
        return ans;
    };
};