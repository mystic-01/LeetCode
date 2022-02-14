class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, best = INT_MIN;
        for (auto i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) best = max(best, sum);
        };
        return (double) best / k;
    };
};