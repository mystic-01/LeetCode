class Solution {
public: 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), dp[n + 2];
        for (int i = 0; i < n + 2; i++) {
            dp[i] = 0;
        };
        for (int idx = n - 1; idx >= 0; idx--) {
            dp[idx] = cost[idx] + min(dp[idx + 1], dp[idx + 2]);    
        };
        return min(dp[0], dp[1]);
    };  
};      