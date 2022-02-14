class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> dp(n, 0);
        
        for (auto i = 2; i < n; i++) nums[i] += *max_element(nums.begin(), nums.begin() + i - 1);
        if (n == 1) return nums[0];
        return max(nums[n - 1], nums[n - 2]);
    };
};