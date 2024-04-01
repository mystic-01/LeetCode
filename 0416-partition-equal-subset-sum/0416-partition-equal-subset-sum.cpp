class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totSum = accumulate(begin(nums), end(nums), 0), target = totSum / 2;
        if (totSum % 2) {
            return false;            
        };
        sort(begin(nums), end(nums), greater<int>());
        vector<int> dp(target + 1, false), prev(target + 1, false);
        
        prev[target] = true;
        
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int sum = target; sum >= 0; --sum) {
                if (sum + nums[idx] <= target) {
                    if (prev[sum + nums[idx]]) {
                        dp[sum] = true;
                    };
                };
                dp[sum] = dp[sum] || prev[sum];
            };     
            prev = dp;
        };
        return prev[0];
    };
};