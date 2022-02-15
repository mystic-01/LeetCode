class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        for (auto i = 1; i < n; i++) ans ^= nums[i];
        return ans;
    };
};