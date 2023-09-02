class Solution {
public:
    int recurse(int idx, int len, string &s, set<string> &st, int (*dp)[52]) {
        if (idx == s.size()) return 0;
        if (idx + len > s.size()) return 1e7;
        
        if (dp[idx][len] != -1) return dp[idx][len]; 
        
        int take = 1e7, takeExtraLen = 1e7, notTake = 1e7;
            
        if (idx + len <= s.size() && st.count(s.substr(idx, len))) take = recurse(idx + len, 1, s, st, dp);
        takeExtraLen = recurse(idx, len + 1, s, st, dp);
        notTake = 1 + recurse(idx + 1, 1, s, st, dp);
        
        return dp[idx][len] = min({take, takeExtraLen, notTake});
    };
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int dp[52][52];
        
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                dp[i][j] = -1;
            };        
        };
        
        set<string> st;
        for (auto &str : dictionary) st.insert(str);
        return recurse(0, 1, s, st, dp);
    };
};