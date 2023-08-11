class Solution {
public:
    int recurse(int idx, int amountLeft, vector<int>& coins, vector<vector<int>> &dp) {
        if (amountLeft == 0) return dp[idx][amountLeft] = 1;
        if (idx == coins.size()) return dp[idx][amountLeft] = 0;
        
        if (dp[idx][amountLeft] != -1) return dp[idx][amountLeft];
        
        int take = 0;
        if (amountLeft - coins[idx] >= 0) take = recurse(idx, amountLeft - coins[idx], coins, dp);
        
        int notTake = recurse(idx + 1, amountLeft, coins, dp);
        return dp[idx][amountLeft] = take + notTake;
    };
    
    int change(int amount, vector<int>& coins) {
        // coins should not have dupes
        // sort(coins.begin(), coind.end());
        
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        
        
        
        return recurse(0, amount, coins, dp);
    };
};