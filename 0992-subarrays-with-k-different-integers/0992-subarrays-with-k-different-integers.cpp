class Solution {
public:
    // When they say exactly k, think (0 to k) - (0 to k - );
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, ans = 0;
        unordered_map<int, int> m;
        for (int i = 0, left = 0; i < n; ++i) {
            ++m[nums[i]];
            while (left < n && m.size() > k) {
                if (--m[nums[left]] == 0) {
                    m.erase(nums[left]);
                };    
                ++left;
            };
            ans += (i - left + 1);
        };
        return ans;
    };
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    };
};