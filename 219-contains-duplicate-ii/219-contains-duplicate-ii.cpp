class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return 1;
            m[nums[i]] = i; 
        };
        return 0;
    };
};