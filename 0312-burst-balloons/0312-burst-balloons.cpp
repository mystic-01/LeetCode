class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        for (int i = n; i >= 1; --i) {
            for (int j = 1; j <= n; ++j) {
                if (i <= j) {
                    for (int mid = i; mid <= j; ++mid) {
                        int coins = (nums[i - 1] * nums[mid] * nums[j + 1]) + dp[i][mid - 1] + dp[mid + 1][j];
                        dp[i][j] = max(dp[i][j], coins);
                    };
                };
            };        
        };
        
        return dp[1][n];
    };
};