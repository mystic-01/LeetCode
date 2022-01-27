class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), best = 0, zeroCount = 0, lastZeroIndex = 0;
        for (auto i = 0; i < n; i++) {
            if (!nums[i] && zeroCount++ >= k) while (lastZeroIndex < n && nums[lastZeroIndex++] != 0);
            best = max(best, i + 1 - lastZeroIndex);
        };
        return best;
    };
};