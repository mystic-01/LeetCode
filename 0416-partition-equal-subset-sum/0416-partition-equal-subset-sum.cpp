class Solution {
public:
    bool recurse(int idx, int sum, int &target, vector<int> &nums, vector<vector<int>> &dp) {
        if (idx == nums.size()) {
            return sum == target;            
        };
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        };
        if (sum + nums[idx] <= target) {
            if (recurse(idx + 1, sum + nums[idx], target, nums, dp)) {
                return dp[idx][sum] = true;
            };
        };
        return dp[idx][sum] = recurse(idx + 1, sum, target, nums, dp);
    };
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(begin(nums), end(nums), 0), target = sum / 2;
        if (sum % 2) {
            return false;            
        };
        sort(begin(nums), end(nums), greater<int>());
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return recurse(0, 0, target, nums, dp);
    };
};