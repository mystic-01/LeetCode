class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), best = 0, count = 0, left = 0;
        for (auto i = 0; i < n; i++) {
            if (!nums[i] && count++ >= k) while (left < n && nums[left++]);
            best = max(best, i + 1 - left);
        };
        return best;
    };
};