class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        for (int i = 0, left = 0; i < n; ++i) {
            if (i > 0 && nums[i] != nums[i - 1] - 1) {
                left = i;
            };
            count += (i - left + 1);
        };
        return count;
    };
};