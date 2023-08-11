class Solution {
public:
    int recurse(int pos, int &n, int *dp) {
        if (pos == n) return 1;
        if (pos > n) return 0;
        
        if (dp[pos] != -1) return dp[pos];
        
        int takeOne = recurse(pos + 1, n, dp);                
        int takeTwo = recurse(pos + 2, n, dp);                

        return dp[pos] = takeOne + takeTwo;            
    };
    
    int climbStairs(int n) {
        int dp[n + 2];
        for (int i = 0; i < n + 2; i++) dp[i] = -1;    
        return recurse(0, n, dp);
    };
};