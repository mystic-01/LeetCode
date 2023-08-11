class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 2];
        for (int i = 0; i < n + 2; i++) dp[i] = 0;    

        dp[n] = 1, dp[n + 1] = 0;
        
        for (int pos = n - 1; pos >= 0; pos--) {
            int takeOne = dp[pos + 1];
            int takeTwo = dp[pos + 2];
            dp[pos] = takeOne + takeTwo;                                                    
        };
        
        return dp[0];
    };
};