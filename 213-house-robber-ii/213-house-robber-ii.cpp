class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> copy = nums;
        int prev1 = nums[0], prev2 = nums[1], ans = 0;
        
        for (auto i = 2; i < n - 1; i++) nums[i] += prev1, prev1 = max(prev1, prev2), prev2 = nums[i];
        for (auto i : nums) ans = max(ans, i);
        
        prev1 = copy[n - 1], prev2 = copy[n - 2];
        for (auto i = n - 3; i > 0; i--) copy[i] += prev1, prev1 = max(prev1, prev2), prev2 = copy[i];
        for (auto i : copy) ans = max(ans, i);
        return ans;
    };
};