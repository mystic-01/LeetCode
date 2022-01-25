class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, best = 0;
        while (i < j) best = max(best,  (j - i) * (nums[i] < nums[j] ? nums[i++] : nums[j--]));
        return best;
    };
};
