class Solution {
public:
    int recurse (int n, vector<int> &dp) {
        if (n > 10 || n < 2) return 0;
        if (n == 2) return 81;
        return dp[n] = recurse(n - 1, dp) * (10 - n + 1);     
    };
    
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        vector<int> dp(9, 0);
        dp[1] = 10, dp[2] = 81;
        recurse(n, dp);
        return accumulate(dp.begin(), dp.begin() + n + 1, 0);
    };
};