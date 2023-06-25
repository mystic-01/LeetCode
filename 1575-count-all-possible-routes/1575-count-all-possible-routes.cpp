class Solution {
public:
    int recurse(int start, int &end, int fuel, int &mod, vector<int> &loc, int (*dp)[201]) {
        if (fuel < 0) return 0;
        int ans = (start == end);
        
        if (dp[start][fuel] != -1) return dp[start][fuel];
        
        for (auto i = 0; i < loc.size(); i++) {
            if (i != start) ans = ((long)ans + recurse(i, end, fuel - abs(loc[i] - loc[start]), mod, loc, dp)) % mod;        
        };
        
        return dp[start][fuel] = ans;
    };        
    
    int countRoutes(vector<int>& locations, int start, int end, int fuel) {
        
        int dp[101][201], mod = 1e9 + 7;
        
        for (auto i = 0; i < 101; i++) {
            for (auto j = 0; j < 201; j++) {
                dp[i][j] = -1;
            };
        };
        
        return recurse(start, end, fuel, mod, locations, dp);        
    };
};