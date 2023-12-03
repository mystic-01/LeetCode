class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ops = 0;
        for (int i = 1; i < n; ++i) {
            ops += max(nums[i - 1] - nums[i] + 1, 0);
            nums[i] = max(nums[i], nums[i - 1] + 1);
        };
        return ops;
    };
};