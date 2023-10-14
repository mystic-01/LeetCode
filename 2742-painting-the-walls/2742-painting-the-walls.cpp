class Solution {
public:
    int recurse(int idx, int walls, vector<int>& cost, vector<int>& time, int (*dp)[501]) {
        if (walls <= 0) return 0;
        if (idx >= cost.size()) return 1e9;

        if (dp[idx][walls] != -1) return dp[idx][walls];
        
        int take = cost[idx] + recurse(idx + 1, walls - time[idx] - 1, cost, time, dp);
        int notTake = recurse(idx + 1, walls, cost, time, dp);        
        
        return dp[idx][walls] = min(take, notTake);
    };
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int dp[501][501];
        for(int i = 0; i < 501; ++i) {
            for(int j = 0; j < 501; ++j) {
                dp[i][j] = -1;
            };
        };
        return recurse(0, cost.size(), cost, time, dp);        
    };
};

/*



*/