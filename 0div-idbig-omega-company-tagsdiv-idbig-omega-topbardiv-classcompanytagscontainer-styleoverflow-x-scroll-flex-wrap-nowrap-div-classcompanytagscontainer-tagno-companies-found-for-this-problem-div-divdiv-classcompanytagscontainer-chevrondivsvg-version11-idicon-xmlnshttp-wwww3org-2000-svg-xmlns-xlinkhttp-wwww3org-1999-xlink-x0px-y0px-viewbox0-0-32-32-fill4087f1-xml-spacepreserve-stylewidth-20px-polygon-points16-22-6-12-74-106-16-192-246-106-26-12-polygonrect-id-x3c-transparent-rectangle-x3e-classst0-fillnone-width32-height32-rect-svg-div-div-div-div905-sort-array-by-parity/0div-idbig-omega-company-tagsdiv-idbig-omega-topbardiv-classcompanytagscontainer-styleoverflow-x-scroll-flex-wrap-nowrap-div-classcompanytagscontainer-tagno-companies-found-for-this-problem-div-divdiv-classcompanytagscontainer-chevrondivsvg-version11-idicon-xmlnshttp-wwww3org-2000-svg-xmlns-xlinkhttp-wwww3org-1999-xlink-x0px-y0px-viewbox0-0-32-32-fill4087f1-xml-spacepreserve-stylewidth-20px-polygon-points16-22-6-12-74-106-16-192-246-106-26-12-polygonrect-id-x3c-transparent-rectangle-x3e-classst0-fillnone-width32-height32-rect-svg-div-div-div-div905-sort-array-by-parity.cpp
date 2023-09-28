class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(), start = 0;
        while (start < n && nums[start] % 2 == 0) {
            start++;
        };
        
        for (int i = start + 1; i < n; ++i) {
            if (start < n && nums[i] % 2 == 0) swap(nums[start++], nums[i]);
        };
        
        return nums;
    };
};