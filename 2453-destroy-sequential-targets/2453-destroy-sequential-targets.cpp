class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size(), maxCount = 0, maxCountSeed = INT_MAX;
        unordered_map<int, pair<int, int>> m;
        for (int i = 0; i < n; i++) {
            int mod = nums[i] % space;
            m[mod].second = (m.find(mod) != m.end()) ? min(m[mod].second, nums[i]) : nums[i];
            m[mod].first += 1;

            if ((m[mod].first > maxCount) || (m[mod].first == maxCount && m[mod].second < maxCountSeed)) {
                maxCount = m[mod].first, maxCountSeed = m[mod].second;
            };
        };
        return maxCountSeed;        
    };
};