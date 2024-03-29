class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), maxElement = *max_element(begin(nums), end(nums));
        long long ans = 0, freq = 0, count = 0;
        for (int i = 0, left = 0; i < n; ++i) {
            freq += nums[i] == maxElement;
            while (freq == k && left <= i) {
                ++count;
                freq -= nums[left++] == maxElement;
            };
            ans += count;
        };
        return ans;
    };
};