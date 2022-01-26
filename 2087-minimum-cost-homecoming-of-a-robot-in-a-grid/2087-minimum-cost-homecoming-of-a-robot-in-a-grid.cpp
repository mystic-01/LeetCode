class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;
        
        if (start[0] > home[0]) {
            for (int i = home[0]; i < start[0]; i++) cost += rowCosts[i];                
        } else {
            for (int i = start[0]; i < home[0]; i++) cost += rowCosts[i + 1];                
        };
        
        if (start[1] > home[1]) {
            for (int i = home[1]; i < start[1]; i++) cost += colCosts[i];                
        } else {
            for (int i = start[1]; i < home[1]; i++) cost += colCosts[i + 1];                
        };
        return cost;
    };
};