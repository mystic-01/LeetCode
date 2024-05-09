class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long n = nums.size(), maxHappiness = 0, taken = 0, i = n - 1;
        sort(begin(nums), end(nums));
        while (k--) {
            maxHappiness += max(0LL, (long long)nums[i--] - taken++);            
        };
        return maxHappiness;
    };
};