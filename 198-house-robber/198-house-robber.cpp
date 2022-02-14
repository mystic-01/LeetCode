class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev1 = nums[0], prev2 = nums[1];
        
        vector<int> dp(n, 0);
        for (auto i = 2; i < n; i++) nums[i] += prev1, prev1 = max(prev1, prev2), prev2 = nums[i];
        return max(nums[n - 1], nums[n - 2]);
    };
};