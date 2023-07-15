class Solution {
public:
    int recurse(int idx, int k, int &n, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if (idx == n || k == 0) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int i = idx + 1;
        while (i < n) {
            if (events[idx][1] < events[i][0]) break;
            else i++;
        };
        
        int take = events[idx][2] + recurse(i, k - 1, n, events, dp);
        int notTake = recurse(idx + 1, k, n, events, dp);
        
        return dp[idx][k] = max(take, notTake);
    };
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));            
        
        return recurse(0, k, n, events, dp);
    };
};