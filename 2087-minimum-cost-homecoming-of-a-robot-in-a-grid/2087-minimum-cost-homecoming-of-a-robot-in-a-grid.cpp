class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& rowCosts, vector<int>& colCosts) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int cost = 0;
        for (int i = home[0]; i < start[0]; i++) cost += rowCosts[i];                
        for (int i = start[0]; i < home[0]; i++) cost += rowCosts[i + 1];                
        for (int i = home[1]; i < start[1]; i++) cost += colCosts[i];                
        for (int i = start[1]; i < home[1]; i++) cost += colCosts[i + 1];                
        return cost;
    };
};