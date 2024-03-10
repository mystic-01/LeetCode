class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        int n = nums.size(), limit = 0;
        long long totalSumOfHeights = 0, currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum = nums[i];
            limit = nums[i];
            for (int j = i - 1; j >= 0; --j) {
                limit = min(limit, nums[j]);
                currSum += limit;
            };
            limit = nums[i];
            for (int j = i + 1; j < n; ++j) {
                limit = min(limit, nums[j]);
                currSum += limit;
            };
            totalSumOfHeights = max(totalSumOfHeights, currSum);
        };
        return totalSumOfHeights;
    };
};