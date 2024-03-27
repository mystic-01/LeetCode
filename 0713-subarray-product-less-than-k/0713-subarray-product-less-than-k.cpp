class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), prod = 1, count = 0;
        for (int i = 0, left = 0; i < n; ++i) {
            prod *= nums[i];
            while (prod >= k && left <= i) {
                prod /= nums[left++];    
            };
            count += (i - left + 1);
        };
        return count;
    };
};