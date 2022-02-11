class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i = 0; i < nums.size(); i++) if (++m[nums[i]] > 1) return 1;
        return 0;
    };
};