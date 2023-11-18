class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size(), i = 0, j = 0;
        for (long sum = 0; j < n; ++j) {
            sum += nums[j];
            if (sum + k < (long)nums[j] * (j - i + 1)) {
                sum -= nums[i++];
            };
        };
        return j - i;
    };
};