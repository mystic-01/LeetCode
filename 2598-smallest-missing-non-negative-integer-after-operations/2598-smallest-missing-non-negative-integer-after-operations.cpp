class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int val) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            nums[i] %= val;
            if (nums[i] < 0) {
                nums[i] += val;            
            };
            ++m[nums[i]];
        };
        for (int i = 0; i <= n; ++i) {
            if (m[i % val]-- == 0) {
                return i;
            };
        };
        return ans;
    };
};