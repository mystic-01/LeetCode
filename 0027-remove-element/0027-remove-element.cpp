class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), start = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) swap(nums[i], nums[start++]);
        };
        return start;
    };
};