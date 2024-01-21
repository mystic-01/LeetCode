class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        for (int i = 2; i < n; ++i) {
            nums[i] += max(nums[i - 2], i - 3 >= 0 ? nums[i - 3] : 0);    
        };
        return max(nums[n - 1], n - 2 >= 0 ? nums[n - 2] : 0);
    };
};