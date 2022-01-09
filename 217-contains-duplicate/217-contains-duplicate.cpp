class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1]) return true;
        return false;
    };
};