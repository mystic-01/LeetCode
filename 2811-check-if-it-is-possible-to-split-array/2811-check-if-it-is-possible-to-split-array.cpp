class Solution {
public:
    bool recurse(int i, int j, int *pre, vector<int>& nums, int &m, int (*dp)[101]) {
        if (j - i <= 1) return dp[i][j] = true;
        
        int totSum = pre[j] - pre[i] + nums[i];
        if (totSum < m) return dp[i][j] = false;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int takeOutLeft = totSum - nums[i];
        int takeOutRight = totSum - nums[j];
        
        bool left = takeOutLeft >= m ? recurse(i + 1, j, pre, nums, m, dp) : false;
        bool right = takeOutRight >= m ? recurse(i, j - 1, pre, nums, m, dp) : false;
        
        return dp[i][j] = left || right;
    };
    
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size(), pre[n];
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];
        
        int dp[101][101];
        for (int j = 0; j < 100 + 1; j++) {
            for (int k = 0; k < 100 + 1; k++) {
                dp[j][k] = -1;
            };
        };
        return recurse(0, n - 1, pre, nums, m, dp);
    };
};