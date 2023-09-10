class Solution {
public:
    bool recurse(int n, bool isAlice, int (*dp)[2]) {
        if (n == 1) return !isAlice;

        if (dp[n][isAlice] != -1) return dp[n][isAlice];
        
        int ans = isAlice ? 0 : 1;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                if (!isAlice) ans = ans && (recurse(n - i, !isAlice, dp));    
                else ans = ans || (recurse(n - i, !isAlice, dp));    
            };
        };
        return dp[n][isAlice] = ans;
    };
    
    bool divisorGame(int n) {
        int dp[n + 1][2];
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = dp[i][1] = -1;
        };
        return recurse(n, true, dp);    
    };
};