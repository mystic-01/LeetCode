class Solution {
public:
    int recurse(int i, int sum, int &row, int &col, vector<vector<int>> &nums, int &target, vector<vector<int>> &dp) {
        if (i == row) {
            return abs(target - sum);    
        };     
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        };
        int closest = 1e8;
        for (int k = 0; k < col; ++k) {
            // cout << i << " - " << abs(target - (sum + nums[i][k])) << " " << abs(target - sum) << "\n";
            closest = min(closest, recurse(i + 1, sum + nums[i][k], row, col, nums, target, dp));
        };
        return dp[i][sum] = closest;
    };
    
    int minimizeTheDifference(vector<vector<int>>& nums, int target) {
        int row = nums.size(), col = nums[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(4901, -1));
        int ans = recurse(0, 0, row, col, nums, target, dp);
        return ans;
    };
};