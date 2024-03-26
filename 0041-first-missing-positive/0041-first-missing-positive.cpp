class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), end = n - 1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = INT_MAX;
            };            
        };
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (idx < n && nums[idx] > 0) {
                nums[idx] *= -1;
            };            
        };        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;    
            };
        };
        return n + 1;        
    };
};