class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0), prev(amount + 1, 0);
        
        for (int i = 0; i < n + 1; i++) dp[0] = prev[0] = 1;            
        
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int amountLeft = 0; amountLeft <= amount; amountLeft++) {
                int take = 0;
                if (amountLeft - coins[idx] >= 0) take = dp[amountLeft - coins[idx]];
                
                int notTake = prev[amountLeft];
                dp[amountLeft] = take + notTake;                                
            };    
            prev = dp;
        };
        return dp[amount];
    };
};



