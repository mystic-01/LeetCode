class Solution {
public:
    
    int subarrayWithSumLessThanEqualToK(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, sum = 0, count = 0;
        if (k < 0) return 0;
        
        for (auto i = 0; i < n; i++) {
            sum += nums[i];
            while (sum > k && left < n) sum -= nums[left++];
            count += (i - left + 1);
        };
        return count;
    };
    
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return subarrayWithSumLessThanEqualToK(nums, k) - subarrayWithSumLessThanEqualToK(nums, k - 1);
    };
};