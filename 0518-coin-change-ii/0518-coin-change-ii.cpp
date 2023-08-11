class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        
        for (int i = 0; i < n + 1; i++) dp[i][0] = 1;            
        
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int amountLeft = 0; amountLeft <= amount; amountLeft++) {
                int take = 0;
                if (amountLeft - coins[idx] >= 0) take = dp[idx][amountLeft - coins[idx]];
                
                int notTake = dp[idx + 1][amountLeft];
                
                dp[idx][amountLeft] = take + notTake;                                
            };                    
        };
        return dp[0][amount];
    };
};



