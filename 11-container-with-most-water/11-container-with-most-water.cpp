class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1, curr = 0, best = 0;
        while (i < j) {
            if (nums[i] < nums[j]) curr = (j - i) * nums[i++];
            else curr = (j - i) * nums[j--];
            best = max(best, curr);
        };
        return best;
    };
};
