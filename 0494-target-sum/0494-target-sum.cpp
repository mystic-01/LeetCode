class Solution {
public:
    int permute(int idx, int target, vector<int> &nums, int &n, vector<vector<int>> &dp) {
        if (idx == n) {
            return (target == 0) ? 1 : 0;
        };
        if (dp[idx][target + 1000] != -1) {
            return dp[idx][target + 1000];    
        };
        int count = 0;
        count += permute(idx + 1, target - nums[idx], nums, n, dp);
        count += permute(idx + 1, target + nums[idx], nums, n, dp);
        return dp[idx][target + 1000] = count;
    };

    // Use dp here, after watching dp series.     
    // I did!!! - 6th Feb 2023 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int targetOffset = target + 2000;
        vector<vector<int>> dp(n, vector<int>(targetOffset + 1, -1));
        return permute(0, target, nums, n, dp);
    };
};