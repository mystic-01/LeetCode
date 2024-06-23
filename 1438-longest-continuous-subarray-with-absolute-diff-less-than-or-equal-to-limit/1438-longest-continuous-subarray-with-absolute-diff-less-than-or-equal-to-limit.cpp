class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), best = 0, left = 0;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
            auto it = begin(m);
            auto it2 = rbegin(m);
            while (it2->first - it->first > limit) {
                if (--m[nums[left]] == 0) {
                    m.erase(nums[left]);    
                };
                ++left;
                it = begin(m);
                it2 = rbegin(m);
            };
            best = max(best, i - left + 1);
        };
        return best;
    };
};