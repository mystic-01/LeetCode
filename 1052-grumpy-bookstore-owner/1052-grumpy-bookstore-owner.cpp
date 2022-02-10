// bonus = ideal customers = actual customers
class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& grumpy, int k) {
        int n = nums.size(), sum = 0, bonus = 0, maxBonus = 0;
        for (auto i = 0; i < n; i++) {
            sum += grumpy[i] ? 0 : nums[i];
            bonus += grumpy[i] ? nums[i] : 0;

            if (i >= k) bonus -= grumpy[i - k] ? nums[i - k] : 0;
            if (i >= k - 1) maxBonus = max(maxBonus, bonus);
        };
        return sum + maxBonus;
    };
};