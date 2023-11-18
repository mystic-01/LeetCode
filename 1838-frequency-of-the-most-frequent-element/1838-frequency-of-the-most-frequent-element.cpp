class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size(), i = 0, j = 0;
        long sum = 0;
        for (; j < n; ++j) {
            sum += nums[j];
            if ((long)sum + k < (long)nums[j] * (j - i + 1)) {
                sum -= nums[i++];
            };
        };
        return j - i;
    };
};