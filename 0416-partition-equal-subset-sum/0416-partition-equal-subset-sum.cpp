class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(begin(nums), end(nums), 0), target = sum / 2;
        if (sum % 2) {
            return false;            
        };
        sort(begin(nums), end(nums), greater<int>());
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, false));
        
        dp[n][target] = true;
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int sum = target; sum >= 0; --sum) {
                if (sum + nums[idx] <= target) {
                    if (dp[idx + 1][sum + nums[idx]]) {
                        dp[idx][sum] = true;
                    };
                };
                dp[idx][sum] = dp[idx][sum] || dp[idx + 1][sum];
            };            
        };
        return dp[0][0];
    };
};