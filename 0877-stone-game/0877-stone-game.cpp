class Solution {
public:
    int recurse(int i, int j, vector<int>& nums, int (*dp)[501]) {
        if (i > j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int aliceLeftBobLeft = nums[i] + recurse(i + 2, j, nums, dp); 
        int aliceLeftBobRight = nums[i] + recurse(i + 1, j - 1, nums, dp); 
        int aliceRightBobLeft = nums[j] + recurse(i + 1, j - 1, nums, dp); 
        int aliceRightBobRight = nums[j] + recurse(i, j - 2, nums, dp); 
    
        return dp[i][j] = max(max(aliceLeftBobLeft, aliceLeftBobRight), max(aliceRightBobLeft, aliceRightBobRight));
    };
    
    bool stoneGame(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), dp[n][501];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 501; j++) {
                dp[i][j] = -1;
            };        
        };
        
        int maxAlice = recurse(0, n - 1, nums, dp); 
        return maxAlice > sum - maxAlice;
    };
};