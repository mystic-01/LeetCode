class Solution {
public:
    int recurse(int idx, vector<int>& nums, int *dp) {
        if (idx == nums.size()) return 1;
        
        if (dp[idx] != -1) return dp[idx];
        
        bool ans = 0;
        int startVal = nums[idx], twoSame = 1, threeSame = 1, threeIncrease = 1;
        
        for (int i = idx + 1; i < nums.size() && i < idx + 3; i++) {
            if (nums[i] == startVal) twoSame++, threeSame++;
            if (nums[i] == nums[i - 1] + 1) threeIncrease++;
        };
        
        if (twoSame >= 2) ans = ans || recurse(idx + 2, nums, dp);
        if (threeSame == 3) ans = ans || recurse(idx + 3, nums, dp);
        if (threeIncrease == 3) ans = ans || recurse(idx + 3, nums, dp);
        
        return dp[idx] = ans;
    };
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size(), dp[n + 1];        
        for (int i = 0; i < n + 1; i++) dp[i] = -1;
        return recurse(0, nums, dp);
    };
};