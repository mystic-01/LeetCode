class Solution {
public:
    auto maxProfit(vector<int>& prices) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        auto best = 0, smallest = INT_MAX;
        for (auto &i : prices) {
            smallest = min(smallest, i);
            best = max(best, i - smallest);
        };
        return best; 
    };
};