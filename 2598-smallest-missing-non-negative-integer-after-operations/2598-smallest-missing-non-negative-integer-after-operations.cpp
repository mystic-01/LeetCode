class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        int n = nums.size(), ans = 0;
        int v[val];
        memset(v, 0, sizeof(v));
        for (int i = 0; i < n; ++i) {
            nums[i] %= val;
            if (nums[i] < 0) {
                nums[i] += val;            
            };
            ++v[nums[i]];
        };
        for (int i = 0; i <= n; ++i) {
            if (v[i % val]-- == 0) {
                return i;
            };
        };
        return ans;
    };
};