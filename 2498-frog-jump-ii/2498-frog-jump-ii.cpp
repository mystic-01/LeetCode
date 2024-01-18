class Solution {
public:
    int maxJump(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i + 2 < n) ans = max(ans, abs(nums[i] - nums[i + 2]));            
            if (n - i - 3 >= 0) ans = max(ans, abs(nums[n - i - 1] - nums[n - i - 3]));            
        };
        if (n % 2 == 0) {
            ans = max(ans, abs(nums[n - 2] - nums[n - 1]));            
            ans = max(ans, abs(nums[0] - nums[1]));            
        };
        return ans;
    };
};