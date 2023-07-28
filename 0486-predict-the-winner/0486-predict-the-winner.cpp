class Solution {
public:
    int recursePlayerOneScore(int left, int right, vector<int>& nums, vector<vector<int>>& dp) {
        if (left > right) return 0;
        
        if (dp[left][right] != -1) return dp[left][right];
        
        int oneTakeLeftSecondTakeLeft = nums[left] + recursePlayerOneScore(left + 2, right, nums, dp); // 1 + (233, 7)
        int oneTakeLeftSecondTakeRight = nums[left] + recursePlayerOneScore(left + 1, right - 1, nums, dp); // 1 + (5, 233)
        int oneTakeRightSecondTakeLeft = nums[right] + recursePlayerOneScore(left + 1, right - 1, nums, dp); // 7 + (5, 233)
        int oneTakeRightSecondTakeRight = nums[right] + recursePlayerOneScore(left, right - 2, nums, dp); // 7 + (1, 5) 
        
        return dp[left][right] = max(min(oneTakeLeftSecondTakeLeft, oneTakeLeftSecondTakeRight), min(oneTakeRightSecondTakeLeft, oneTakeRightSecondTakeRight));
    };
    
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(21, vector<int>(21, -1));        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int firstScore = recursePlayerOneScore(0, nums.size() - 1, nums, dp);
        
        return firstScore >= sum - firstScore;
    };
};