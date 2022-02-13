class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, prod = 1, count = 0;
        
        for (auto i = 0; i < n; i++) {
            prod *= nums[i];
            while (prod >= k && left < n) prod /= nums[left++];
            if (prod < k) count += (i - left + 1);
        };
        return count;
    };
};