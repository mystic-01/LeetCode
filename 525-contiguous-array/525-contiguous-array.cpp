class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size(), diff = 0, best = 0;
        m[0] = -1;
        for (auto i = 0; i < n; i++) {
            diff += nums[i] ? 1 : -1;
            if (m.find(diff) != m.end()) best = max(best, i - m[diff]);
            else m[diff] = i;
        };
        return best;
    };
};