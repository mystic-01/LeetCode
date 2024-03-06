class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), left = 0, maxLen = 1;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            auto lo = begin(m);
            auto hi = end(m);
            if (!m.empty()) {        
                --hi;
            };
            // cout << s.size() << "\n";
            while (!m.empty() && (abs(nums[i] - lo->first) > limit || abs(nums[i] - hi->first) > limit)) {
                if (--m[nums[left]] == 0) {
                    m.erase(nums[left]);    
                };
                if (!m.empty()) {        
                    lo = begin(m);
                    hi = end(m), --hi;
                    // cout << i << " " << limit << " " << nums[i] << " " << *lo << "\n";
                };
                ++left;
            };
            // cout << i << " " << left << "\n";
            maxLen = max(maxLen, i - left + 1);
            ++m[nums[i]];
        };
            // cout << "\n";
        return maxLen;
    };
};