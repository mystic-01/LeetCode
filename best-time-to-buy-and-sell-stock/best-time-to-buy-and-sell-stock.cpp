class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
        int low = prices[0], best = 0;
        for (int i = 1; i < prices.size(); i++) {
            best = max(best, prices[i] - low);
            low = min(low, prices[i]);
        };
        return best;
    };
};