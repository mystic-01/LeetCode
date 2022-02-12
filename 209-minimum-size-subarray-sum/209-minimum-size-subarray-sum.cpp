class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, sum = 0, best = INT_MAX;
        
        for(auto i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= target && left < n) {
                best = min(best, i - left + 1);
                sum -= nums[left++];
            };
        };
        return best == INT_MAX ? 0 : best;
    };
};