class Solution {
public:
    bool canJump(int idx, int j, int &n, vector<int> &nums, vector<vector<int>>& dp) {
        if (idx == n - 1) return true;
        if (dp[idx][j] != -1) return dp[idx][j];
        
        bool case1 = false, case2 = false, case3 = false;
        
        for (auto i = idx + 1; i < n; i++) {
            if (nums[i] == nums[idx] + j - 1) {
                case1 = canJump(i, j - 1, n, nums, dp);
            } else if (nums[i] == nums[idx] + j) {
                case2 = canJump(i, j, n, nums, dp);
            } else if (nums[i] == nums[idx] + j + 1) {
                case3 = canJump(i, j + 1, n, nums, dp);
                break;
            };            
        };
        
        return dp[idx][j] = case1 || case2 || case3;
    };

    
    bool canCross(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return canJump(0, 0, n, nums, dp);
    };
};