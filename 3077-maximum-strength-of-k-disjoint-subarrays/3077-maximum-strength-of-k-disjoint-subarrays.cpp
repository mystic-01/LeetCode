static const long long oob = -1e18;
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int kMax) {
        int n = nums.size();
        long long dp[kMax + 1][2], prev[kMax + 1][2];
        for (long long k = 0; k <= kMax; ++k) {
            for (int isStart = 0; isStart <= 1; ++isStart) {
                prev[k][isStart] = dp[k][isStart] = oob;
            };
        };
        
        prev[0][0] = prev[0][1] = 0;
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (long long k = 0; k <= kMax; ++k) {
                for (int isStart = 0; isStart <= 1; ++isStart) {
                    int sign = k % 2 ? 1 : -1;
                    long long take = oob, notTake = oob, val = sign * nums[idx] * k;

                    take = val + max(prev[k][0], (k - 1 >= 0 ? prev[k - 1][1] : oob));
                    if (isStart) {
                        notTake = prev[k][1];
                    };
                    dp[k][isStart] = max(take, notTake);
                };
            };
            for (long long k = 0; k <= kMax; ++k) {
                for (int isStart = 0; isStart <= 1; ++isStart) {
                    prev[k][isStart] = dp[k][isStart];
                };
            };
        };
        return prev[kMax][1];
    };
};