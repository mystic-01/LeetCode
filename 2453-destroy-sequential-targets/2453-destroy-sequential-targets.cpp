class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size(), mod[n], maxCount = 0, maxCountSeed = INT_MAX;
        unordered_map<int, pair<int, int>> m;
        for (int i = 0; i < n; i++) {
            mod[i] = nums[i] % space;
            m[mod[i]].second = (m.find(mod[i]) != m.end()) ? min(m[mod[i]].second, nums[i]) : nums[i];
            m[mod[i]].first += 1;

            if ((m[mod[i]].first > maxCount) || (m[mod[i]].first == maxCount && m[mod[i]].second < maxCountSeed)) {
                maxCount = m[mod[i]].first, maxCountSeed = m[mod[i]].second;
            };
        };
        return maxCountSeed;        
    };
};