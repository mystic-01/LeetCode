class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size(), left = 0;
        long long count = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            while (left < n && (sum * (i - left + 1LL)) >= k) {
                sum -= nums[left++];    
            };
            count += (long long)(i - left + 1LL);
        };
        return count;
    };
};