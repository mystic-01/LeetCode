static int mod = 1e9 + 7;

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> nextAllowed = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, 
                                           {2, 6}, {1, 3}, {2, 4}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}};
        vector<vector<int>> dp(n + 1, vector<int>(11, -1));
        
        for (int prev = 0; prev < 11; ++prev) {
            dp[n][prev] = 1;
        };
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int prev = 0; prev < 11; ++prev) {
                int totalNumbers = 0;
                for (int &x : nextAllowed[prev]) {
                    totalNumbers = (totalNumbers + dp[idx + 1][x]) % mod;
                };             
                dp[idx][prev] = totalNumbers;
            };             
        };
        
        return dp[0][10];
    };
};