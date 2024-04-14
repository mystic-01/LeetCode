static const long long oob = -1e18;

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int kMax) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(kMax + 1, vector<long long>(2, oob)));
        dp[n][0][0] = dp[n][0][1] = 0;
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (long long k = 0; k <= kMax; ++k) {
                for (int isStart = 0; isStart <= 1; ++isStart) {
                    int sign = k % 2 ? 1 : -1;
                    long long take = oob, notTake = oob, val = sign * nums[idx] * k;

                    take = val + dp[idx + 1][k][0];
                    take = max(take, val + (k - 1 >= 0 ? dp[idx + 1][k - 1][1] : oob));

                    if (isStart) {
                        notTake = dp[idx + 1][k][1];
                    };
                    dp[idx][k][isStart] = max(take, notTake);
                };
            };            
        };
        return dp[0][kMax][1];
    };
};