class Solution {
public:
    int afi(int n, vector<int> &dp) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
  
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = afi(n - 1, dp) + afi(n - 2, dp);
    };
    
    int fib(int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        vector<int> dp(n + 1, -1);
        return afi(n, dp);
    };
};