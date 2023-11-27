static int mod = 1e9 + 7;

class Solution {
    
public:
    
    int recurse(int idx, int prev, int &n, vector<vector<int>> &nextAllowed, vector<vector<int>> &dp) {
        if (idx == n) return dp[idx][prev] = 1;
        if (dp[idx][prev] != -1) return dp[idx][prev];
        
        int totalNumbers = 0;
        for (int &x : nextAllowed[prev]) {
            totalNumbers = (totalNumbers + recurse(idx + 1, x, n, nextAllowed, dp)) % mod;
            
        };        
        return dp[idx][prev] = totalNumbers;
    };
    
    int knightDialer(int n) {
        vector<vector<int>> nextAllowed = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, 
                                           {2, 6}, {1, 3}, {2, 4}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
        vector<vector<int>> dp(n + 1, vector<int>(11, -1));
        return recurse(0, 10, n, nextAllowed, dp);
    };
};