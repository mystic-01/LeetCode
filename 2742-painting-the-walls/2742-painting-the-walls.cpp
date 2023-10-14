class Solution {
public:
    const int unmasker = 501;
    
    int recurse(int mask, vector<int>& cost, vector<int>& time, int *dp) {
        int idx = mask % unmasker, walls = mask / unmasker;
        if (walls <= 0) return 0;
        if (idx >= cost.size()) return 1e9;

        if (dp[mask] != -1) return dp[mask];
        int take = cost[idx] + recurse(idx + 1 + ((walls - time[idx] - 1) * unmasker), cost, time, dp);
        int notTake = recurse(idx + 1 + (walls * unmasker), cost, time, dp);        
        
        return dp[mask] = min(take, notTake);
    };
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int dp[251001];
        
        for(int i = 0; i < 251001; ++i) {
            dp[i] = -1;
        };
        return recurse(cost.size() * unmasker, cost, time, dp);        
    };
};

/*



*/