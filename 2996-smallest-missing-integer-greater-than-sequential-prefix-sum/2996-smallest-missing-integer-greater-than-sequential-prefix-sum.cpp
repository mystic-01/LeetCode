class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(), i = 1, maxSum = nums[0];
        while (i < n && nums[i] == nums[i - 1] + 1) {
            maxSum += nums[i++];        
        };
        sort(begin(nums), end(nums));
        int ans = maxSum; 
        for (int i = 0; i < n; ++i) {
            if (nums[i] == ans) {
                ++ans;
            };
        };        
        return ans;        
    };
};