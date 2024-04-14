static const long long oob = -1e18;
class Solution {
public:
    long long recurse(int idx, long long k, int isStart, vector<int> &nums, vector<vector<vector<long long>>> &dp) {
        if (k < 0) {
            return oob;            
        };
        if (idx == nums.size()) {
            if (k == 0) {
                return 0;
            } else {
                return oob;
            };
        };

        if (dp[idx][k][isStart] != oob) {
            return dp[idx][k][isStart];            
        };

        int sign = k % 2 ? 1 : -1;
        long long take = oob, notTake = oob, val = sign * nums[idx] * k;
        
        // take = val + recurse(idx + 1, k, 0, nums, dp);
        // startNew = val + recurse(idx + 1, k - 1, 1, nums, dp);
        take = val + recurse(idx + 1, k, 0, nums, dp);
        take = max(take, val + recurse(idx + 1, k - 1, 1, nums, dp));
        
        if (isStart) {
            notTake = recurse(idx + 1, k, 1, nums, dp);
        };
        return dp[idx][k][isStart] = max(take, notTake);
    };
    
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(2, oob)));
        return recurse(0, k, 1, nums, dp);
    };
};