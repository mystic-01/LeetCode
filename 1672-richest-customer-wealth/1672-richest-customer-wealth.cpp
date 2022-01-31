class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0, best = 0;
        for (auto i : accounts) {
            sum = 0;
            for (auto j : i) sum += j;                
            best = max(best, sum);
        };
        return best;
    };
};