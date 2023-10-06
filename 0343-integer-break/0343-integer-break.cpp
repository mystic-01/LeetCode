class Solution {
public:
    int recurse(int n, int *dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        
        // Only already split numbers come here, hence they can themselves be their best answer, thus 'ans' for 2 here can be 2.  
        int ans = n;
        for (int i = 1; i < n; ++i) {
            int curr = recurse(i, dp) * recurse(n - i, dp);
            ans = max(ans, curr);
        };
        
        return dp[n] = ans;
    };
    
    int integerBreak(int n) {
        int dp[60] = {-1}, ans = 1;
        // Here the number 'n' has not been bisected yet, so for the time being it cannot be it's own answer.
        // Because we need to split it into k >= 2
        
        for (int i = 0; i < 60; ++i) {
            dp[i] = -1;
        };
        
        for (int i = 1; i < n; ++i) {
            int curr = recurse(i, dp) * recurse(n - i, dp);
            ans = max(ans, curr);
        };
        return ans;
    };
};