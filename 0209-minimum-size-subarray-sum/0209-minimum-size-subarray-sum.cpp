class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, sum = 0, len = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (left < n && sum >= target) {
                len = min(len, i - left + 1);
                sum -= nums[left++];    
            };
        };
        
        return len == INT_MAX ? 0 : len;
    };
};