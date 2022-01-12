class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        auto smallest = INT_MAX, best = -1;
        auto n = nums.size() - 1;
        for (auto &i : nums) {
            smallest = min(smallest, i); 
            if (i != smallest) best = max(best, i - smallest);                 
        };
        return best;
    };
};