class Solution {
public:
    int recurse(int idx, int &n, vector<int> &cost, int *dp) {
        if (idx >= n) return 0;        
        if (dp[idx] != -1) return dp[idx];

        int one = cost[idx] + recurse(idx + 1, n, cost, dp);
        int two = cost[idx] + recurse(idx + 2, n, cost, dp);
        return dp[idx] = min(one, two);        
    };
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), dp[n + 1];
        for (int i = 0; i < n + 1; i++) dp[i] = -1;
        return min(recurse(0, n, cost, dp), recurse(1, n, cost, dp));    
    };
};