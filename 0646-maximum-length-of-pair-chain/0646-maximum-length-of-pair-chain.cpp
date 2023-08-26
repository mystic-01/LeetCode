class Solution {
public:
    int recurse(int idx, int end, vector<vector<int>> &nums, int (*dp)[2002]) {
        if (idx == nums.size()) return 0;
        
        if (dp[idx][end + 1001] != -1) return dp[idx][end + 1001];
        
        int take = 0, notTake = 0;
        if (nums[idx][0] > end) take = 1 + recurse(idx + 1, nums[idx][1], nums, dp);
        notTake = recurse(idx + 1, end, nums, dp);
        
        return dp[idx][end + 1001] = max(take, notTake);
    };
    
    int findLongestChain(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());        
        int dp[1001][2002];
        
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 2002; j++) {
                dp[i][j] = -1;
            };
        };
        
        return recurse(0, -1001, nums, dp);
    };
};