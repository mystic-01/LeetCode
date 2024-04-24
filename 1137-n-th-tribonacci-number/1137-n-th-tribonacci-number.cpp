class Solution {
public:
    int tribonacci(int n) {
        int dp[3] = {0, 1, 1};
        for (int i = 3; i <= n; ++i) {
            int sum = dp[0] + dp[1] + dp[2];
            dp[i % 3] = sum;
        };
        return dp[n % 3];
    };
};