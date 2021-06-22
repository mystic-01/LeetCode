class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], current = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current = max(nums[i], current+nums[i]);
            best = max(best, current);
        };
        return best;
    };
};