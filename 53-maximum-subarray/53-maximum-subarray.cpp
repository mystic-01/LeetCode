class Solution {
public:
    auto maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = -100000, best = -100000;
        for (auto i = 0; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            best = max(best, sum);
        };
        return best;
    };
};
