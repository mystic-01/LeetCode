class Solution {
public:
    auto maxSubArray(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);  
        auto best = INT_MIN, sum = 0;
        for (auto i = 0; i < nums.size(); i++)
            best = max(best, sum = max(nums[i], sum + nums[i]));
        return best;
    };
};
