class Solution {
public:
    int recurse(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if (i > j) {
            return 0;    
        };
        if (dp[i][j] != -1) {
            return dp[i][j];     
        };
        int maxCoins = 0;
        for (int mid = i; mid <= j; ++mid) {
            int coins = (nums[i - 1] * nums[mid] * nums[j + 1]) + recurse(i, mid - 1, nums, dp) + recurse(mid + 1, j, nums, dp);
            maxCoins = max(maxCoins, coins);
        };
        return dp[i][j] = maxCoins;
    };
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return recurse(1, n, nums, dp);
    };
};