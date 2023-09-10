class Solution {
public: 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), curr = 0, prev1 = 0, prev2 = 0;
        for (int idx = n - 1; idx >= 0; idx--) {
            curr = cost[idx] + min(prev1, prev2);
            prev2 = prev1, prev1 = curr;
        };
        return min(prev2, prev1);
    };  
};      