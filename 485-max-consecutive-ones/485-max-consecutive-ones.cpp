class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), best = 0, count = 0;
        for (auto i = 0; i < n; i++) {
            if (nums[i]) count++;
            else best = max(best, count), count = 0;
        };
        return max(best, count);
    };
};